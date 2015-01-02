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

	// No dedi support for now!
	if (Global::Game::Type == GAME_TYPE_DEDI) return FALSE;

	char* result = Global::Dependency::Loaded();

	if (result)
	{
		MessageBox(0, va("Dependency '%s' not loaded!", result), PROJECTLONG, MB_ICONERROR);
		return FALSE;
	}

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

	Global::Main::PreInitSucceeded = true;
	return TRUE;
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