#include "..\STDInclude.h"

// Version 40 addresses as default

// Colored name
DWORD Addresses::ColoredName           = 0x64C31F;

// Colored names ingame
DWORD Addresses::ClientUserinfoChanged = 0x81ED10;

// CL_GetClientName
DWORD Addresses::GetClientName         = 0x61E650;

// Killfeed
DWORD Addresses::GetClientName1        = 0x7A2939;
DWORD Addresses::GetClientName2        = 0x7A29AC;

// Spectator
DWORD Addresses::GetClientName3        = 0x9773D3;

// Demo
DWORD Addresses::GetClientName4        = 0x9773D3;

// Chat
DWORD Addresses::GSayCleanChat         = 0x98D72D;

// I_CleanStr hook
DWORD Addresses::ICleanStrHook         = 0x61E6EA;
DWORD Addresses::ICleanStr             = 0x6DAF80;

// Min name length
DWORD Addresses::NameLength1           = 0x4C8BAB;
DWORD Addresses::NameLength2           = 0x4A2C53;

// Colortables
DWORD Addresses::ColorTableFloat       = 0xC63C50;
DWORD Addresses::ColorTableByte        = 0xD254B8;

void Addresses::Assign()
{
	Addresses::AssignFromPattern();

	switch (Global::Game::Version)
	{
		case GAME_VERSION_39:
		{
			// Colored name
			Addresses::ColoredName           = 0x6F27AF;

			// Colored names ingame
			Addresses::ClientUserinfoChanged = 0x8120F0;

			// Min name length
			Addresses::NameLength1           = 0x52FFAB;
			Addresses::NameLength2           = 0x54DDD3;

			// Colortables
			Addresses::ColorTableFloat       = 0xC26690;
			Addresses::ColorTableByte        = 0xCE4BB8;
			break;
		}

		case GAME_VERSION_41:
		{
			// Colored name
			Addresses::ColoredName           = 0x40906F;

			// Colored names ingame
			Addresses::ClientUserinfoChanged = 0x81F230;

			// Min name length
			Addresses::NameLength1           = 0x4CF5AB;
			Addresses::NameLength2           = 0x53B0C3;

			// Colortables
			Addresses::ColorTableFloat       = 0xC64840;
			Addresses::ColorTableByte        = 0xD24A28;
			break;
		}

		case GAME_VERSION_43:
		{
			// Colored name
			Addresses::ColoredName           = 0x6286FF;

			// Colored names ingame
			Addresses::ClientUserinfoChanged = 0x820830;

			// CL_GetClientName
			Addresses::GetClientName         = 0x5B0F50;

			// Killfeed
			Addresses::GetClientName1        = 0x7A4129;
			Addresses::GetClientName2        = 0x7A419C;

			// Spectator
			Addresses::GetClientName3        = 0x9795A3;

			// Demo
			Addresses::GetClientName4        = 0x98F97D;

			// I_CleanStr hook
			Addresses::ICleanStrHook         = 0x5B0FEA;
			Addresses::ICleanStr             = 0x44F2B0;

			// Min name length
			Addresses::NameLength1           = 0x53F25B;
			Addresses::NameLength2           = 0x5F0283;

			// Colortables
			Addresses::ColorTableFloat       = 0xC6EC80;
			Addresses::ColorTableByte        = 0xD30A08;
			break;
		}

		case GAME_VERSION_DEDI_DEBUG:
		{
			// Colored name
			Addresses::ColoredName           = 0; // Dedi doesn't need that

			// Colored names ingame
			Addresses::ClientUserinfoChanged = 0x5BC6C0;

			// CL_GetClientName
			Addresses::GetClientName         = 0x511900;

			// Killfeed
			Addresses::GetClientName1        = 0x44E169;
			Addresses::GetClientName2        = 0x44E24E;

			// Spectator
			Addresses::GetClientName3        = 0; // Dedi doesn't need that

			// Demo
			Addresses::GetClientName4        = 0; // Dedi doesn't need that

			// I_CleanStr hook
			Addresses::ICleanStrHook         = 0x51198B;
			Addresses::ICleanStr             = 0x78E6B0;

			// Min name length
			Addresses::NameLength1           = 0x6E69DB;
			Addresses::NameLength2           = 0x6E6B96;

			// Colortables
			Addresses::ColorTableFloat       = 0xBBACA0;
			Addresses::ColorTableByte        = 0xD1E084;
			break;
		}
	}
}

void Addresses::AssignFromPattern()
{
	//TODO: Use patterns
	Addresses::GSayCleanChat = (DWORD)Patterns::FindPattern((uint8_t*)"\xE8\x00\x00\x00\x00\x8B\x15\x00\x00\x00\x00\x52\xE8\x00\x00\x00\x00\x8B\x8C\x24\x00\x00\x00\x00", "x????xx????xx????xxx????");
}