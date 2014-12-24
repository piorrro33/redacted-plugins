/*
	The Redacted T6 project uses research by Bas Timmer, the OpenSteamworks project and codresearch(.com). 

	Purpose of this file: Interact with the game's notification system
	Initial author: momo5502
	Started: 2014-07-31
*/

#include "..\STDInclude.h"

int Notify::NumParams;

void Notify::Push(char* value)
{
	Functions::Scr_AddString(0, value);
	Notify::NumParams++;
}

void Notify::Push(gentity_t* value)
{
	Functions::Scr_AddEntity(0, value);
	Notify::NumParams++;
}

void Notify::Push(int value)
{
	Functions::Scr_AddInt(0, value);
	Notify::NumParams++;
}

void Notify::NotifyClient(int clientNum, char* notify)
{
	// Convert notify command into a string reference
	short s_notify = Functions::SL_GetString(notify, 0);

	// Notify with pushed params for given client
	Functions::Scr_NotifyNum(clientNum, 0, s_notify, Notify::NumParams);

	// Reset param count
	Notify::NumParams = 0;
}
