/*
	The Redacted T6 project uses research by Bas Timmer, the OpenSteamworks project and codresearch(.com). 

	Purpose of this file: Defining public bot stuff.
	Initial author: momo5502
	Started: 2014-07-31
*/

class Bots
{
	public:

		static void Initialize();
		static void Spawn(int count);

	private:

		static void InitializeStaff();

		static void Spawn_f();
		static void ChangeClass_f();
};
