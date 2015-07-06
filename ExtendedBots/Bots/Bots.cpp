/*
	The Redacted T6 project uses research by Bas Timmer, the OpenSteamworks project and codresearch(.com). 

	Purpose of this file: Finally, bot spawning through command :D
	Initial author: momo5502
	Started: 2014-07-31
*/

#include "..\STDInclude.h"

// TODO: Fill that list with names
char* Bots::NameList[] =
{
	"momo5502",
	"Convery",
	"Posavec00",
	"YourMum",
	"Jesus",
	"CreaTed",
	"Anarchy",
	"Ahex",
	"Icecream",
	"Magic",
	"avol",
	"Impasta",
	"Noob622",
	"Bag",
	"Storm",
	"dekart811",
	"malex",
	"fourZeroTwo",
	"DVonderhaar",
	"Larry",
	"Mr. TalkingBadger",
	"Walter White",
	"Steve Ballmer",
	"Dr. Axel Stoll",
	"dodokay",
	"Detlev",
	"Kevin",
	"Chantal",
	"Schackeline",
	"GLaDOS",
	"potato",
	"Dasfonia",
	"BassPro241",
	"Mikl_da_Pikle",
	"Vyriant",
	"Diabeetus",
	"Wilford Brimley",
	"Ded Rededtion",
	"Wade",
	"Hank",
	"Waldo",
	"Chet",
	"Irving",
	"Juan",
	"Pistachio",
	"Pensi Didlo",
	"embient_mp_highrise",
};

void Bots::Initialize()
{
	// Replace staff array with custom one
	*(char***)Addresses::BotArray1 = Bots::NameList;
	*(char***)Addresses::BotArray2 = Bots::NameList;
	*(char***)Addresses::BotArray3 = Bots::NameList;

	// Apply new array size
	int size = (sizeof(Bots::NameList) / sizeof(Bots::NameList[0]));
	*(BYTE*)Addresses::BotArraySize1 = size;
	*(BYTE*)Addresses::BotArraySize2 = size;
	*(BYTE*)Addresses::BotArraySize3 = size;
	*(BYTE*)Addresses::BotArraySize4 = size;

	// Apply new clan tags
	*(char**)Addresses::BotTag1 = "connect \"\\invited\\1\\cg_predictItems\\1\\cl_anonymous\\0\\color\\4\\head\\default\\model\\multi\\snaps\\20\\rate\\5000\\name\\%s\\clanAbbrev\\" BOT_CLAN_TAG "\\xuid\\%s\\xnaddr\\%s\\natType\\2\\protocol\\%d\\netfieldchk\\%d\\sessionmode\\%d\\migrating\\1\"";
	*(char**)Addresses::BotTag2 = "connect \"\\invited\\1\\cg_predictItems\\1\\cl_anonymous\\0\\color\\4\\head\\default\\model\\multi\\snaps\\20\\rate\\5000\\name\\%s\\clanAbbrev\\" BOT_CLAN_TAG "\\xuid\\%s\\xnaddr\\%s\\natType\\2\\protocol\\%d\\netfieldchk\\%d\\sessionmode\\%d\\qport\\%d\"";
}

void Bots::PostInit()
{
	// Register commands
	Global::Dependency::Import::Cmd_AddCommand("spawnBot", Bots::Spawn_f);
	Global::Dependency::Import::Cmd_AddCommand("autoChangeClass", Bots::ChangeClass_f);
}

void Bots::Spawn_f()
{
	unsigned int count = (Global::Dependency::Import::Cmd_ArgC() > 1 ? atoi(Global::Dependency::Import::Cmd_ArgV(1)) : 1);

	// Check if ingame and host
	if (Functions::SV_Loaded())
	{
		if (!strcmp(Global::Dependency::Import::Cmd_ArgV(1), "all"))
		{
			Bots::Spawn(-1);
			Global::Dependency::Import::Com_Printf(1, "Max. amount of bots spawned successfully!\n");
		}
		else
		{
			Bots::Spawn(count);
			Global::Dependency::Import::Com_Printf(1, "%d bots spawned successfully!\n", count);
		}
	}
	else
	{
		Global::Dependency::Import::Com_Printf(1, "You need to be host to spawn bots!\n");
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

void Bots::Spawn(unsigned int count)
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
	Global::Dependency::Import::Cmd_ExecuteCommand("wait 100;", false);

	for (unsigned int i = 0; i < entRefs.size(); i++)
	{
		// Change bot class
		Global::Dependency::Import::Cmd_ExecuteCommand(va("autoChangeClass %d;", entRefs[i]->number), false);
	}
}
