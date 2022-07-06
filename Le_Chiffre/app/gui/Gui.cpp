#include "../Include.h"
#include "../../was_ist_das.Hpp"
using namespace zuiun;

bool zuiun::trigger = false;
bool zuiun::aim = false;
bool zuiun::glow = false;
bool zuiun::radar = false;
bool zuiun::flash = false;
bool zuiun::bhop = false;

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(
	HWND window,
	UINT message,
	WPARAM wideParameter,
	LPARAM longParameter
);


long __stdcall WindowProcess(
	HWND window,
	UINT message,
	WPARAM wideParameter,
	LPARAM longParameter)
{
	if (ImGui_ImplWin32_WndProcHandler(window, message, wideParameter, longParameter))
		return true;
	switch (message)
	{
	case WM_SIZE:
	{
		if (gui::device && wideParameter != SIZE_MINIMIZED)
		{
			gui::presentParameters.BackBufferWidth = LOWORD(longParameter);
			gui::presentParameters.BackBufferHeight = HIWORD(longParameter);
			gui::ResetDevice();
		}
	}return 0;
	case WM_SYSCOMMAND:
	{
		if ((wideParameter & 0xfff0) == SC_KEYMENU)
			return 0;
	} break;
	case WM_DESTROY: 
	{
		PostQuitMessage(0);
	} return 0;
	case WM_LBUTTONDOWN:
	{
		gui::position = MAKEPOINTS(longParameter);
	} return 0;
	case WM_MOUSEMOVE: 
	{
		if (wideParameter == MK_LBUTTON)
		{
			const auto points = MAKEPOINTS(longParameter);
			auto rect = ::RECT{ };

			GetWindowRect(gui::window, &rect);

			rect.left += points.x - gui::position.x;
			rect.top += points.y - gui::position.y;

			if (gui::position.x >= 0 &&
				gui::position.x <= gui::WIDTH &&
				gui::position.y >= 0 && gui::position.y <= 19)
				SetWindowPos(
					gui::window,
					HWND_TOPMOST,
					rect.left,
					rect.top,
					0, 0,
					SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOZORDER
				);
		}
	} return 0;
	}

	return DefWindowProcW(window, message, wideParameter, longParameter);
}

void gui::createHWindow(
	const char* windowName,
	const char* className) noexcept
{
	gui::windowClass.cbSize = sizeof(WNDCLASSEXA);
	gui::windowClass.style = CS_CLASSDC;
	gui::windowClass.lpfnWndProc = WindowProcess;
	gui::windowClass.cbClsExtra = 0;
	gui::windowClass.cbWndExtra = 0;
	gui::windowClass.hInstance = GetModuleHandleA(0);
	gui::windowClass.hIcon = 0;
	gui::windowClass.hCursor = 0;
	gui::windowClass.hbrBackground = 0;
	gui::windowClass.lpszMenuName = 0;
	gui::windowClass.lpszClassName = className;
	gui::windowClass.hIconSm = 0;

	RegisterClassExA(&gui::windowClass);

	gui::window = CreateWindowA(
		className,
		windowName,
		WS_POPUP,
		100,
		100,
		gui::WIDTH,
		gui::HEIGHT,
		0,
		0,
		gui::windowClass.hInstance,
		0
	);

	ShowWindow(gui::window, SW_SHOWDEFAULT);
	UpdateWindow(gui::window);
}
void gui::DestroyHWindow() noexcept
{
	DestroyWindow(gui::window);
	//UnregisterClass(gui::windowClass.lpszClassName, gui::windowClass.hInstance);
}

bool gui::CreateDevice() noexcept
{
	gui::d3d = Direct3DCreate9(D3D_SDK_VERSION);

	if (!gui::d3d)
		return false;

	ZeroMemory(&gui::presentParameters, sizeof(gui::presentParameters));

	gui::presentParameters.Windowed = TRUE;
	gui::presentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	gui::presentParameters.BackBufferFormat = D3DFMT_UNKNOWN;
	gui::presentParameters.EnableAutoDepthStencil = TRUE;
	gui::presentParameters.AutoDepthStencilFormat = D3DFMT_D16;
	gui::presentParameters.PresentationInterval = D3DPRESENT_INTERVAL_ONE;

	if (gui::d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		gui::window,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&gui::presentParameters,
		&gui::device) < 0)
		return false;
	return true;
}
void gui::ResetDevice() noexcept
{
	ImGui_ImplDX9_InvalidateDeviceObjects();

	const auto result = gui::device->Reset(&gui::presentParameters);

	if (result == D3DERR_INVALIDCALL)
		IM_ASSERT(0);

	ImGui_ImplDX9_CreateDeviceObjects();
}
void gui::DestroyDevice() noexcept
{
	if (gui::device)
	{
		gui::device->Release();
		gui::device = nullptr;
	}

	if (gui::d3d)
	{
		gui::d3d->Release();
		gui::d3d = nullptr;
	}
}

void gui::CreateImGui() noexcept
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ::ImGui::GetIO();

	io.IniFilename = NULL;

	ImGui::StyleColorsDark();

	ImGui_ImplWin32_Init(gui::window);
	ImGui_ImplDX9_Init(gui::device);
}
void gui::DestroyImGui() noexcept
{
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

void gui::BeginRender() noexcept
{
	MSG message;
	while (PeekMessage(&message, 0, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

}
void gui::EndRender() noexcept
{
	ImGui::EndFrame();

	gui::device->SetRenderState(D3DRS_ZENABLE, FALSE);
	gui::device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
	gui::device->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);

	gui::device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(0, 0, 0, 255), 1.0f, 0);

	if (gui::device->BeginScene() >= 0)
	{
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		gui::device->EndScene();
	}

	const auto result = gui::device->Present(0, 0, 0, 0);

	if (result == D3DERR_DEVICELOST && gui::device->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
		ResetDevice();
}
void gui::Render() noexcept
{

	//Modules m;
	ImGui::SetNextWindowPos({ 0, 0 });
	ImGui::SetNextWindowSize({ gui::WIDTH, gui::HEIGHT });
	ImGui::Begin(
		"das  Chiffre",
		&gui::exit,
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoSavedSettings |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_MenuBar
	);
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("Info"))
		{
			if(ImGui::MenuItem("Author", "Twitter:@M3351AN")) { }
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}

	ImGui::Checkbox("Debug", &gui_modules::debug);
	if (gui_modules::debug)
	{
		ShowWindow(GetConsoleWindow(), SW_SHOW);
	}
	else 
	{
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	}

	ImGui::Spacing();
	ImGui::Separator();

	ImGui::Text("Counter-Strike: Global Offensive");
	ImGui::Checkbox("Aimbot", &gui_modules::guiaim);
	if (gui_modules::guiaim)
	{
		zuiun::aim = true;
	}
	else {
		zuiun::aim = false;
	}
	ImGui::Checkbox("Triggerbot[LAlt]", &gui_modules::guitrigger);
	if (gui_modules::guitrigger)
	{
		zuiun::trigger = true;
	}
	else {
		zuiun::trigger = false;
	}
	ImGui::Checkbox("Glow", &gui_modules::guiglow);
	if (gui_modules::guiglow)
	{
		zuiun::glow = true;
	}
	else {
		zuiun::glow = false;
	}
	ImGui::Checkbox("Radar", &gui_modules::guiradar);
	if (gui_modules::guiradar)
	{
		zuiun::radar = true;
	}
	else {
		zuiun::radar = false;
	}
	ImGui::Checkbox("Bhop", &gui_modules::guibhop);
	if (gui_modules::guibhop)
	{
		zuiun::bhop = true;
	}
	else {
		zuiun::bhop = false;
	}
	ImGui::Checkbox("No flash", &gui_modules::guiflash);
	if (gui_modules::guiflash)
	{
		zuiun::flash = true;
	}
	else {
		zuiun::flash = false;
	}

	ImGui::Spacing();
	ImGui::Text("Exit [End]");

	ImGui::End();
}