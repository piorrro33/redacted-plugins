class Addresses
{
public:

	// Colored name
	static DWORD ColoredName;

	// Colored names ingame
	static DWORD ClientUserinfoChanged;

	// CL_GetClientName
	static DWORD GetClientName;

	// Killfeed
	static DWORD GetClientName1;
	static DWORD GetClientName2;

	// Spectator
	static DWORD GetClientName3;

	// I_CleanStr hook
	static DWORD ICleanStrHook;
	static DWORD ICleanStr;

	// Min name length
	static DWORD NameLength1;
	static DWORD NameLength2;

	// Colortables
	static DWORD ColorTableFloat;
	static DWORD ColorTableByte;

	static void Assign();
	static void AssignFromPattern();
};
