#define PROJECTLONG "ExtendedConsole"

// Game version definition
typedef enum GameVersion
{
	GAME_VERSION_39,
	GAME_VERSION_40,
	GAME_VERSION_41,
	GAME_VERSION_43,
	GAME_VERSION_DEDI_DEBUG,
	//GAME_VERSION_DEDI_SHIP,
	GAME_VERSION_ERROR = -1
};

// Game type definition
typedef enum GameType
{
	GAME_TYPE_MP,
	GAME_TYPE_ZM,
	GAME_TYPE_DEDI,
	GAME_TYPE_ERROR = -1
};

// Global class
class Global
{
	public:

		// Game specific class
		class Game
		{
			public:

				static GameVersion Version;
				static GameType    Type;

				static void DetectGame();
				static bool IsValidGame();
		};

		// Dependency handler
		class Dependency
		{
			public:

				static char* List[];

				static int   Count();
				static char* Get(int index);
				static char* Loaded();
		};

		class Main
		{
			public:

				static int PreInit();
				static int PostInit();
				static int ParseMessage(const char* message);
		};
};
