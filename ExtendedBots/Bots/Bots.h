/*
	The Redacted T6 project uses research by Bas Timmer, the OpenSteamworks project and codresearch(.com). 

	Purpose of this file: Defining public bot stuff.
	Initial author: momo5502
	Started: 2014-07-31
*/

#define BOT_CLAN_TAG "RED"

class Bots
{
	public:

		static void Initialize();
		static void PostInit();
		static unsigned int Spawn(unsigned int count);

	private:

		static char* NameList[];

		static void Spawn_f();
		static void ChangeClass_f();
};
