#include "..\STDInclude.h"

#pragma region APIExport

EXPORT int32_t __stdcall PreInit()
{
	return Global::Main::PreInit();
}

EXPORT int32_t __stdcall PostInit()
{
	return Global::Main::PostInit();
}

EXPORT int32_t __stdcall AuthorInfo()
{
	//printf("https://github.com/momo5502\n");
	return (int32_t)"momo5502";
}

EXPORT int32_t __stdcall ExtendedInfo()
{
	return (int32_t)(PROJECTLONG "\n");
}

EXPORT int32_t __stdcall OfficialMod()
{
	// Let's consider this an official one ;)
	return TRUE;
}

// Dependencies that need to be loaded.
EXPORT int32_t __stdcall DependencyCount()
{
	//return 0; // SteamAPI seems to be bugged
	return Global::Dependency::Count();
}

EXPORT const char * __stdcall GetDependency(uint32_t Index)
{
	return Global::Dependency::Get(Index);
}

EXPORT int32_t __stdcall SendMessageB(const char *Message)
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