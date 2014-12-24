/*
	The Redacted T6 project uses research by Bas Timmer, the OpenSteamworks project and codresearch(.com). 

	Purpose of this file: Finally, bot spawning through command :D
	Initial author: momo5502
	Started: 2014-07-31
*/

#include "..\STDInclude.h"


void Bots::Initialize()
{
	Global::Dependency::Import::Cmd_AddCommand("spawnBot", Bots::Spawn_f);
	Global::Dependency::Import::Cmd_AddCommand("autoChangeClass", Bots::ChangeClass_f);

	Bots::InitializeStaff();
}

void Bots::InitializeStaff()
{
	// TODO: Replace botname array
}

void Bots::Spawn_f()
{
	int count = (Global::Dependency::Import::Cmd_ArgC() > 1 ? atoi(Global::Dependency::Import::Cmd_ArgV(1)) : 1);

	// Check if ingame and host
	if (Functions::SV_Loaded())
	{
		if (!strcmp(Global::Dependency::Import::Cmd_ArgV(1), "all"))
		{
			Bots::Spawn(-1);
			Global::Dependency::Import::Com_Printf("Max. amount of bots spawned successfully!\n");
		}
		else
		{
			Bots::Spawn(count);
			Global::Dependency::Import::Com_Printf("%d bots spawned successfully!\n", count);
		}
	}
	else
	{
		Global::Dependency::Import::Com_Printf("You need to be host to spawn bots!\n");
	}
}

void Bots::ChangeClass_f()
{
	if (Global::Dependency::Import::Cmd_ArgC() != 2) return;
	int client = atoi(Global::Dependency::Import::Cmd_ArgV(1));

	// TODO: Probably add different class types? Or do bots automatically pick different weapons anyways?
	Notify::Push("class_assault");
	Notify::Push("changeclass");
	Notify::NotifyClient(client, "menuresponse");
}

void Bots::Spawn(int count)
{
	int error = 0;

	// Add desired amount of bots
	std::vector<gentity_t*> entRefs;

	for (unsigned int i = 0; i < count; i++)
	{
		Sleep(10);

		gentity_t* entRef = Functions::SV_AddTestClient();

		if (entRef)
		{
			entRefs.push_back(entRef);
		}
		else
		{
			error++;

			if (error == 3)
				break;
		}
	}

	// Wait 1 second for the bots to join the game
	Global::Dependency::Import::Cmd_ExecuteCommand("wait 100;");

	for (int i = 0; i < entRefs.size(); i++)
	{
		// Change bot class
		Global::Dependency::Import::Cmd_ExecuteCommand(va("autoChangeClass %d;", entRefs[i]->number));
	}
}
