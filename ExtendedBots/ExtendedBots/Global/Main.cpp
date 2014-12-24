#include "..\STDInclude.h"

int Global::Main::PreInit()
{
	// Check environment
	if (!Global::Game::IsValidGame())
	{
		MessageBox(0, "Invalid game environment!", PROJECTLONG, MB_ICONERROR);
		return FALSE;
	}

	char* result = Global::Dependency::Loaded();

	if (result)
	{
		MessageBox(0, va("Dependency '%s' not loaded!", result), PROJECTLONG, MB_ICONERROR);
		return FALSE;
	}

	if (Global::Game::Type == GAME_TYPE_ZM) return FALSE; // Only MP!

	// Assign values according to the current gameversion
	Functions::Assign();

	// Main initialization
// 	Input::Initialize();
// 	Console::Initialize();
// 	Renderer::Initialize();

	return TRUE;
}

int Global::Main::PostInit()
{
	return TRUE;
}

int Global::Main::ParseMessage(const char* message)
{
	return TRUE;
}