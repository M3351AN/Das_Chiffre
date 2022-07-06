#ifndef INTERNALISATION_EN_HPP
#define INTERNALISATION_EN_HPP
#pragma once
#include <map>
#include <string>

#include "../misc/xor.hpp"

namespace i18n {
	std::map<std::string, std::wstring> en {
		{XorStr("on"), XorStrW(L"ON")},
		{XorStr("off"), XorStrW(L"OFF")},
		{XorStr("yes"), XorStrW(L"YES")},
		{XorStr("no"), XorStrW(L"NO")},
		{XorStr("loading"), XorStrW(L"LOADING")},
		{XorStr("outdated"), XorStrW(L"OUTDATED")},
		{XorStr("latest"), XorStrW(L"LATEST")},
		{XorStr("error"), XorStrW(L"ERROR")},
		{XorStr("hold"), XorStrW(L"HOLD")},
		{XorStr("press"), XorStrW(L"PRESS")},
		{XorStr("waiting"), XorStrW(L"WAITING")},
		{XorStr("connecting"), XorStrW(L"CONNECTING")},
		{XorStr("website"), XorStrW(L"Github:https://github.com/M3351AN/das_chiffre")},
		{XorStr("state"), XorStrW(L"State")},
		//{XorStr("language"), XorStrW(L"Language (F1)")},
		{XorStr("connected_csgo"), XorStrW(L"Connected to CS:GO process")},
		{XorStr("connected_game"), XorStrW(L"Connected to active game")},
		{XorStr("version"), XorStrW(L"Version")},
		{XorStr("cheat_functions"), XorStrW(L"You should open gui first.")},
		{XorStr("bunny_hop"), XorStrW(L"Bunny hop")},
		{XorStr("no_flash"), XorStrW(L"No flashbang")},
		{XorStr("aimbot"), XorStrW(L"Aimbot")},
		{XorStr("triggerbot"), XorStrW(L"Activate trigger bot")},
		{XorStr("use_triggerbot"), XorStrW(L"Use trigger bot[LAlt]")},
		{XorStr("glowesp"), XorStrW(L"Glow ESP")},
		{XorStr("radar_hack"), XorStrW(L"Radar hack")},
		{XorStr("gui"), XorStrW(L"Show Gui [INS]")},
		{XorStr("exit"), XorStrW(L"Immediate exit [END]")}
	};
}
#endif // INTERNALISATION_EN_HPP