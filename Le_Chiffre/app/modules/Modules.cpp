//#include "../Include.h"
/*
SDK sdk;

void Modules::CustomFOV()
{
	if (sdk.Localplayer())
	{
		
	}
}

void Modules::Thirdperson()
{
	if (sdk.Localplayer())
	{
		if (GetAsyncKeyState(VK_NUMPAD0))
		{
			sdk.Write(sdk.Thirdperson(), 0);
		}
		else if (GetAsyncKeyState(VK_NUMPAD1))
		{
			sdk.Write(sdk.Thirdperson(), 1);
		}
		else if (GetAsyncKeyState(VK_NUMPAD2))
		{
			sdk.Write(sdk.Thirdperson(), 2);
		}
	}
}

void Modules::Aimbot()
{
	if (sdk.Localplayer())
	{

	}
}

void Modules::Bhop()
{
	if (sdk.Localplayer())
	{
		if (GetAsyncKeyState(VK_SPACE) && sdk.Onground() & (1 << 0))
		{
			sdk.Write(sdk.Bhop(), 6);
		}
	}
}

void Modules::NoRecoil()
{
	if (sdk.Localplayer())
	{

	}
}

void Modules::Triggerbot()
{
	if (sdk.Localplayer())
	{
		if (sdk.Crosshair() != 0 && sdk.Crosshair() < 64)
		{
			if (sdk.eTeam() != sdk.Localteam() && sdk.eHealth() > 0 && sdk.eHealth() < 101)
			{
				sdk.Write(sdk.Triggerbot(), 5);
				std::this_thread::sleep_for(std::chrono::milliseconds(20));
				sdk.Write(sdk.Triggerbot(), 4);
			}
		}
	}
}*/