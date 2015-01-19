#include "..\STDInclude.h"

// Version 40
SL_GetString_t       Functions::SL_GetString       = (SL_GetString_t)0x6F5A50;
SL_ConvertToString_t Functions::SL_ConvertToString = (SL_ConvertToString_t)0x4FE530;
Scr_NotifyNum_t      Functions::Scr_NotifyNum      = (Scr_NotifyNum_t)0x53D5D0;
Scr_AddString_t      Functions::Scr_AddString      = (Scr_AddString_t)0x6AB5E0;
Scr_AddEntity_t      Functions::Scr_AddEntity      = (Scr_AddEntity_t)0x5C9580;
Scr_AddInt_t         Functions::Scr_AddInt         = (Scr_AddInt_t)0x4E1C20;
Scr_GetString_t      Functions::Scr_GetString      = (Scr_GetString_t)0x6608D0;
SV_AddTestClient_t   Functions::SV_AddTestClient   = (SV_AddTestClient_t)0x62C140;
SV_Loaded_t          Functions::SV_Loaded          = (SV_Loaded_t)0x580AA0;

void Functions::Assign()
{
	Functions::AssignFromPattern();

	switch (Global::Game::Version)
	{
		case GAME_VERSION_43:
		{
			Functions::SL_GetString       = (SL_GetString_t)0x602C40;
			Functions::SL_ConvertToString = (SL_ConvertToString_t)0x422D10;
			Functions::Scr_NotifyNum      = (Scr_NotifyNum_t)0x578690;
			Functions::Scr_AddString      = (Scr_AddString_t)0x4F1650;
			Functions::Scr_AddEntity      = (Scr_AddEntity_t)0x4C20F0;
			Functions::Scr_AddInt         = (Scr_AddInt_t)0x57AFF0;
			Functions::Scr_GetString      = (Scr_GetString_t)0x67C6A0;
			Functions::SV_AddTestClient   = (SV_AddTestClient_t)0x5514B0;
			Functions::SV_Loaded          = (SV_Loaded_t)0x510FC0;
			break;
		}

		case GAME_VERSION_DEDI_DEBUG:
		{
			Functions::SL_GetString = (SL_GetString_t)0x837080;
			Functions::SL_ConvertToString = (SL_ConvertToString_t)0x835C00;
			Functions::Scr_NotifyNum = (Scr_NotifyNum_t)0x846DA0;
			Functions::Scr_AddString = (Scr_AddString_t)0x847BB0;
			Functions::Scr_AddEntity = (Scr_AddEntity_t)0x634280;
			Functions::Scr_AddInt = (Scr_AddInt_t)0x8478E0;
			Functions::Scr_GetString = (Scr_GetString_t)0x852D70;
			Functions::SV_AddTestClient = (SV_AddTestClient_t)0x6EA460;
			Functions::SV_Loaded = (SV_Loaded_t)0x6EDD20;
			break;
		}
	}
}

void Functions::AssignFromPattern()
{
	// TODO: Add patterns
}