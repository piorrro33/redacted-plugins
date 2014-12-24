// Types
typedef unsigned int(__cdecl * SL_GetString_t)(const char *str, unsigned int user);
typedef const char *(_cdecl* SL_ConvertToString_t)(unsigned int stringValue);
typedef void(__cdecl * Scr_NotifyNum_t)(int entnum, unsigned int classnum, unsigned int stringValue, unsigned int paramcount);
typedef void(__cdecl * Scr_AddString_t)(scriptInstance_t inst, const char *value);
typedef void(__cdecl * Scr_AddEntity_t)(scriptInstance_t inst, gentity_t *ent);
typedef void(__cdecl * Scr_AddInt_t)(scriptInstance_t inst, int value);
typedef const char* (_cdecl* Scr_GetString_t)(scriptInstance_t inst, unsigned int index);
typedef gentity_t* (__cdecl * SV_AddTestClient_t)();
typedef bool(__cdecl * SV_Loaded_t)();

class Functions
{
public:

	// Functions
	static SL_GetString_t       SL_GetString;
	static SL_ConvertToString_t SL_ConvertToString;
	static Scr_NotifyNum_t      Scr_NotifyNum;
	static Scr_AddString_t      Scr_AddString;
	static Scr_AddEntity_t      Scr_AddEntity;
	static Scr_AddInt_t         Scr_AddInt;
	static Scr_GetString_t      Scr_GetString;
	static SV_AddTestClient_t   SV_AddTestClient;
	static SV_Loaded_t          SV_Loaded;

	static void Assign();
	static void AssignFromPattern();
};
