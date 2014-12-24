class Patches
{
	public:

		static void Apply();

	private:

		static void ClientUserinfoChanged_Hook();
		static char* CL_GetClientName_Hook(int a1, int a2, char* buffer, int a4, int a5);
};