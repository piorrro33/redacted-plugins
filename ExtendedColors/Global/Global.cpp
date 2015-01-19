#include "..\STDInclude.h"

#pragma region Game

GameVersion Global::Game::Version = GAME_VERSION_ERROR;
GameType Global::Game::Type       = GAME_TYPE_ERROR;

// Detect current game version and type
void Global::Game::DetectGame()
{
	switch (*(DWORD*)0x41136F)
	{
		// Version 39
		case 0x75C08500:
		{
			Global::Game::Version = GAME_VERSION_39;
			Global::Game::Type    = GAME_TYPE_ZM;
			break;
		}
		
		// Version 40
		case 0x111F9C35:
		{
			Global::Game::Version = GAME_VERSION_40;
			Global::Game::Type    = GAME_TYPE_MP;
			break;
		}

		// Version 41
		case 0x244C8BCC:
		{
			Global::Game::Version = GAME_VERSION_41;
			Global::Game::Type    = GAME_TYPE_ZM;
			break;
		}

		// Version 43
		case 0x30C4835E:
		{
			Global::Game::Version = GAME_VERSION_43;
			Global::Game::Type    = GAME_TYPE_MP;
			break;
		}

		// Dedicated - debug version
		case 0x0F0C7D8B:
		{
			Global::Game::Version = GAME_VERSION_DEDI_DEBUG;
			Global::Game::Type    = GAME_TYPE_DEDI;
			break;
		}

// 		// Dedicated - ship version
// 		case 0x500B7400:
// 		{
// 			Global::Game::Version = GAME_VERSION_DEDI_SHIP;
// 			Global::Game::Type    = GAME_TYPE_DEDI;
// 			break;
// 		}

		default:
		{
			Global::Game::Version = GAME_VERSION_ERROR;
			Global::Game::Type    = GAME_TYPE_ERROR;
			break;
		}
	}
}

// Check if valid environment
bool Global::Game::IsValidGame()
{
	return (Global::Game::Version != GAME_VERSION_ERROR && Global::Game::Type != GAME_TYPE_ERROR);
}

#pragma endregion

#pragma region Dependency

// Dependency list
char* Global::Dependency::List[] =
{
	"AdvancedMods.Red32n",
};

// Return dependency count
int Global::Dependency::Count()
{
	return (sizeof(Global::Dependency::List) / sizeof(Global::Dependency::List[0]));
}

// Return dependency name
char* Global::Dependency::Get(int index)
{
	if (Global::Dependency::Count() <= index)
	{
		return "404";
	}
	else
	{
		return Global::Dependency::List[index];
	}
}

// Check if all dependencies are loaded, return missing one
char* Global::Dependency::Loaded()
{
	// Get SteamAPI handle
	HMODULE steamAPI = GetModuleHandleA("steam_api.dll");

	// SteamAPI not loaded properly
	if (!steamAPI) return "steam_api.dll";

	// Get isPluginLoaded from SteamAPI
	FARPROC isPluginLoaded = GetProcAddress(steamAPI, "isPluginLoaded");

	// SteamAPI is invalid
	if (!isPluginLoaded) return "steam_api.dll";

	// Loop through necessary dependencies
	for (int i = 0; i < Global::Dependency::Count(); i++)
	{
		int isLoaded = false;
		char* dependency = Global::Dependency::Get(i);

		// Check if invalid dependency
		if (!dependency || !strcmp(dependency, "404"))
		{
			return "404";
		}

		// Check if dependency is loaded
		__asm
		{
			push dependency
			call isPluginLoaded
			add esp, 4h

			mov isLoaded, eax
		}

		// Error loading dependency
		if (!isLoaded)
		{
			return dependency;
		}
	}

	// All dependencies loaded
	return 0;
}

#pragma endregion