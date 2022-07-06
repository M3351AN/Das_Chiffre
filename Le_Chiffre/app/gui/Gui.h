//#include "../Include.h"

namespace gui 
{
	constexpr int WIDTH = 500;
	constexpr int HEIGHT = 300;

	inline bool exit = true;

	inline HWND window = nullptr;
	inline WNDCLASSEXA windowClass = { };

	inline POINTS position = { };

	inline PDIRECT3D9 d3d = nullptr;
	inline LPDIRECT3DDEVICE9 device = nullptr;
	inline D3DPRESENT_PARAMETERS presentParameters = { };

	void createHWindow(
		const char* windowName,
		const char* className) noexcept;
	void DestroyHWindow() noexcept;

	bool CreateDevice() noexcept;
	void ResetDevice() noexcept;
	void DestroyDevice() noexcept;

	void CreateImGui() noexcept;
	void DestroyImGui() noexcept;

	void BeginRender() noexcept;
	void EndRender() noexcept;
	void Render() noexcept;
}

namespace gui_modules
{
	static bool debug = false;

	static bool guibhop = false;
	static bool guiaim = false;
	static bool guitrigger = false;
	static bool guiradar = false;
	static bool guiglow = false;
	static bool guiflash = false;

}