#include "..\STDInclude.h"

#pragma region APIExport

EXPORT int32_t PreInit()
{
	return Global::Main::PreInit();
}

EXPORT int32_t PostInit()
{
	return Global::Main::PostInit();
}

EXPORT int32_t AuthorInfo()
{
	printf("https://github.com/momo5502\n");
	return TRUE;
}

EXPORT int32_t ExtendedInfo()
{
	return (int32_t)"SpawnBot\n";
}

EXPORT int32_t OfficialMod()
{
	// Let's consider this an official one ;)
	return TRUE;
}

// Dependencies that need to be loaded.
EXPORT int32_t DependencyCount()
{
	return 0; // SteamAPI seems to be bugged
	return Global::Dependency::Count();
}

EXPORT const char *GetDependency(uint32_t Index)
{
	return Global::Dependency::Get(Index);
}

EXPORT int32_t SendMessageB(const char *Message)
{
	return Global::Main::ParseMessage(Message);
}

#pragma endregion

#pragma region Entrypoint

// DLL entry point
BOOL WINAPI DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		Global::Game::DetectGame();
	}

	return TRUE;
}

#pragma endregion