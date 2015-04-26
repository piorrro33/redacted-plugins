#include "..\STDInclude.h"

bool Global::Main::PreInitSucceeded = false;

int Global::Main::PreInit()
{
	// Check environment
	if (!Global::Game::IsValidGame())
	{
		MessageBox(0, "Invalid game environment!", PROJECTLONG, MB_ICONERROR);
		return FALSE;
	}

	/*char* result = Global::Dependency::Loaded();

	if (result)
	{
		MessageBox(0, va("Dependency '%s' not loaded!", result), PROJECTLONG, MB_ICONERROR);
		return FALSE;
	}*/

	if (!Global::Dependency::Import::LoadImports())
	{
		MessageBox(0, "Failed to load imports!", PROJECTLONG, MB_ICONERROR);
		return FALSE;
	}

	if (Global::Game::Type == GAME_TYPE_ZM) return FALSE; // Only MP!

	// Assign values according to the current gameversion
	Addresses::Assign();
	Functions::Assign();

	// Main initialization
	Bots::Initialize();

	// Dedi doesn't provide a proper post initialization point
	// So we need this ugly hack
	// Note to convery: Fix PostInit for dedis ;)
	if (Global::Game::Version == GAME_VERSION_DEDI_DEBUG)
	{
		QCALL(0x50839B, Global::Main::InitRendererHook, QPATCH_CALL);
	}

	Global::Main::PreInitSucceeded = true;
	return TRUE;
}

void __declspec(naked) Global::Main::InitRendererHook()
{
	Global::Main::PostInit();

	__asm
	{
		mov eax, 6BC010h // Com_Printf
		jmp eax
	}
}

int Global::Main::PostInit()
{
	if (Global::Main::PreInitSucceeded)
	{
		Bots::PostInit();
	}
	
	return TRUE;
}

int Global::Main::ParseMessage(const char* message)
{
	return TRUE;
}