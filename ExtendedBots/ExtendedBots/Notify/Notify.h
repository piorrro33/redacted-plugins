/*
	The Redacted T6 project uses research by Bas Timmer, the OpenSteamworks project and codresearch(.com). 

	Purpose of this file: Defining public notify stuff.
	Initial author: momo5502
	Started: 2014-07-31
*/

class Notify
{
	public:

		static void Push(char* value);
		static void Push(gentity_t* value);
		static void Push(int value);
		static void NotifyClient(int clientNum, char* notify);

	private:

		static int NumParams;
};