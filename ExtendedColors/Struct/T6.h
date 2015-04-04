typedef int scriptInstance_t;

// I could complete it, but it's not needed in this project
typedef struct gentity_t
{
	int number; // part of entityState_s
	char pad[0x318];
} gentity_t;

enum LocalClientNum_t
{
	INVALID_LOCAL_CLIENT = 0xFFFFFFFF,
	LOCAL_CLIENT_FIRST = 0x0,
	LOCAL_CLIENT_0 = 0x0,
	ONLY_LOCAL_CLIENT = 0x0,
	LOCAL_CLIENT_COUNT = 0x1,
};