//#include "../Include.h"
/*
auto mem = Driver("csgo.exe");

void SDK::Write(DWORD address, int value)
{
	mem.Write<BYTE>(address, value);
}

int SDK::Client()
{
	return mem.GetModuleAddress("client.dll");
}

int SDK::Engine()
{
	return mem.GetModuleAddress("engine.dll");
}

int SDK::Localplayer()
{
	return mem.Read<int32_t>(Client() + dwLocalPlayer);
}

int SDK::Onground()
{
	return mem.Read<bool>(Localplayer() + m_fFlags);
}

int SDK::Thirdperson()
{
	return Localplayer() + m_iObserverMode;
}

int SDK::Bhop()
{
	return Client() + dwForceJump;
}

int SDK::Crosshair()
{
	return mem.Read<int32_t>(Localplayer() + m_iCrosshairId);
}

int SDK::Localteam()
{
	return mem.Read<int32_t>(Localplayer() + m_iTeamNum);
}
int SDK::Player()
{
	return mem.Read<int32_t>(Client() + dwEntityList + (Crosshair() - 1) * 0x10);
}

int SDK::eTeam()
{
	return mem.Read<int32_t>(Player() + m_iTeamNum);
}

int SDK::eHealth()
{
	return mem.Read<int32_t>(Player() + m_iHealth);
}

int SDK::Triggerbot()
{
	return Client() + dwForceAttack;
}*/