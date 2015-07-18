#include "..\STDInclude.h"

#define MIN_NAME_LENGTH 3

bool Patches::skipStringClean = false;

void Patches::Apply()
{
	// Patch RB_LookupColor()
	DWORD* color_table = (DWORD*)Addresses::ColorTableByte;
	color_table[1] = RGB(255, 49, 49);
	color_table[2] = RGB(134, 192, 0);
	color_table[3] = RGB(255, 173, 34);
	color_table[4] = RGB(0, 135, 193);
	color_table[5] = RGB(32, 197, 255);
	color_table[6] = RGB(151, 80, 221);

	// Patch CL_LookupColor()
	for (int i = 0; i < 7 * 4; i++) ((float*)Addresses::ColorTableFloat)[i] = ((BYTE*)color_table)[i] / 255.0f;

	// Reduce min name length
	*(BYTE*)Addresses::NameLength1 = MIN_NAME_LENGTH;
	*(BYTE*)Addresses::NameLength2 = MIN_NAME_LENGTH;

	// Allow colored names
	if (Addresses::ColoredName) QNOP(Addresses::ColoredName, 5);

	// Allow colored names ingame
	QCALL(Addresses::ClientUserinfoChanged, Patches::ClientUserinfoChanged_Stub, QPATCH_JUMP);

	// Allow colors in chat
	QNOP(Addresses::GSayCleanChat, 5);

	// Below is multiplayer only
	if (Global::Game::Type == GAME_TYPE_ZM) return;

	// Apply colors to killfeed
	QCALL(Addresses::GetClientName1, Patches::CL_GetClientName_Stub, QPATCH_CALL);
	QCALL(Addresses::GetClientName2, Patches::CL_GetClientName_Stub, QPATCH_CALL);
	QCALL(Addresses::ICleanStrHook,  Patches::ICleanStr_Stub,        QPATCH_CALL);

	// Colors in spectator
	if (Addresses::GetClientName3) QCALL(Addresses::GetClientName3, Patches::CL_GetClientName_Stub, QPATCH_CALL);

	// Colors in demo overlay
	if (Addresses::GetClientName4) QCALL(Addresses::GetClientName4, Patches::CL_GetClientName_Stub, QPATCH_CALL);
}

void __declspec(naked) Patches::ICleanStr_Stub()
{
	__asm
	{
		xor eax, eax
		mov al, Patches::skipStringClean
		mov Patches::skipStringClean, 0
		test eax, eax

		jnz returnSafe

		jmp Addresses::ICleanStr

	returnSafe:
		retn
	}
}

void __declspec(naked) Patches::ClientUserinfoChanged_Stub()
{
	__asm
	{
		mov eax, [esp + 4h]
		dec eax

		pusha
		push eax // length
		push ecx // name
		push edx // buffer

		call strncpy

		add esp, 0Ch
		popa

		retn
	}
}
		
char* Patches::CL_GetClientName_Stub(LocalClientNum_t localClientNum, int index, char *buf, int _size, bool addClanName)
{
	Patches::skipStringClean = true;

	//QNOP(Addresses::ICleanStrHook, 5);

	__asm
	{
		xor eax, eax
		mov al, addClanName

		push eax
		push _size
		push buf
		push index
		push localClientNum
		call Addresses::GetClientName
		add esp, 14h
	}

	//QCALL(Addresses::ICleanStrHook, Addresses::ICleanStr, QPATCH_CALL);
	strcat(buf, "^7");
}