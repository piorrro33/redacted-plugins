#include "..\STDInclude.h"

// Version 40 addresses as default

// Bot.cpp
DWORD Addresses::BotArray1 = 0x49214B;
DWORD Addresses::BotArray2 = 0x492168;
DWORD Addresses::BotArray3 = 0x4F7DA1;

DWORD Addresses::BotArraySize1 = 0x49213B;
DWORD Addresses::BotArraySize2 = 0x49215B;
DWORD Addresses::BotArraySize3 = 0x4F7D7F;
DWORD Addresses::BotArraySize4 = 0x4F7D94;

DWORD Addresses::BotTag1 = 0x644183;
DWORD Addresses::BotTag2 = 0x62C28C;

void Addresses::Assign()
{
	Addresses::AssignFromPattern();

	switch (Global::Game::Version)
	{
	case GAME_VERSION_43:
	{
		// Bot.cpp
		Addresses::BotArray1 = 0x6A2C8B;
		Addresses::BotArray2 = 0x6A2CA8;
		Addresses::BotArray3 = 0x667E61;

		Addresses::BotArraySize1 = 0x6A2C7B;
		Addresses::BotArraySize2 = 0x6A2C9B;
		Addresses::BotArraySize3 = 0x667E3F;
		Addresses::BotArraySize4 = 0x667E54;

		Addresses::BotTag1 = 0x679BF3;
		Addresses::BotTag2 = 0x5515FC;
		break;
	}
	}
}

void Addresses::AssignFromPattern()
{
	// TODO: Add patterns
}