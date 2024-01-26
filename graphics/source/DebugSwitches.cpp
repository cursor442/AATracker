#include "../../game/header/AA_Tracker.h"

void Game::debugSwitches()
{
	if (dbg.boundbox)
		CheckMenuItem(main_Menu, IDM_DBG_BOUNDBOX, MF_CHECKED);
	else
		CheckMenuItem(main_Menu, IDM_DBG_BOUNDBOX, MF_UNCHECKED);

	switch (dbg.layers)
	{
	case 99:
	{
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_ALL, MF_CHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_0, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_1, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_2, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_3, MF_UNCHECKED);
		break;
	}
	case 0:
	{
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_ALL, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_0, MF_CHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_1, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_2, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_3, MF_UNCHECKED);
		break;
	}
	case 1:
	{
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_ALL, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_0, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_1, MF_CHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_2, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_3, MF_UNCHECKED);
		break;
	}
	case 2:
	{
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_ALL, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_0, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_1, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_2, MF_CHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_3, MF_UNCHECKED);
		break;
	}
	case 3:
	{
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_ALL, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_0, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_1, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_2, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_3, MF_CHECKED);
		break;
	}
	default:
	{
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_ALL, MF_CHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_0, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_1, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_2, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_LAYERS_3, MF_UNCHECKED);
	}
	}

	if (dbg.sections)
		CheckMenuItem(main_Menu, IDM_DBG_SECTIONS, MF_CHECKED);
	else
		CheckMenuItem(main_Menu, IDM_DBG_SECTIONS, MF_UNCHECKED);

	switch (dbg.grid)
	{
	case 0:
	{
		CheckMenuItem(main_Menu, IDM_DBG_GRID_OFF, MF_CHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV2, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV3, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV4, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV5, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV8, MF_UNCHECKED);
		break;
	}
	case 2:
	{
		CheckMenuItem(main_Menu, IDM_DBG_GRID_OFF, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV2, MF_CHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV3, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV4, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV5, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV8, MF_UNCHECKED);
		break;
	}
	case 3:
	{
		CheckMenuItem(main_Menu, IDM_DBG_GRID_OFF, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV2, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV3, MF_CHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV4, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV5, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV8, MF_UNCHECKED);
		break;
	}
	case 4:
	{
		CheckMenuItem(main_Menu, IDM_DBG_GRID_OFF, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV2, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV3, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV4, MF_CHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV5, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV8, MF_UNCHECKED);
		break;
	}
	case 5:
	{
		CheckMenuItem(main_Menu, IDM_DBG_GRID_OFF, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV2, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV3, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV4, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV5, MF_CHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV8, MF_UNCHECKED);
		break;
	}
	case 8:
	{
		CheckMenuItem(main_Menu, IDM_DBG_GRID_OFF, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV2, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV3, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV4, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV5, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV8, MF_CHECKED);
		break;
	}
	default:
	{
		CheckMenuItem(main_Menu, IDM_DBG_GRID_OFF, MF_CHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV2, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV3, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV4, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV5, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_GRID_DIV8, MF_UNCHECKED);
		break;
	}
	}	

	switch (dbg.buttonTab)
	{
	case DBG_SHOW:
	{
		CheckMenuItem(main_Menu, IDM_DBG_BTN_TAB_SHOW, MF_CHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_BTN_TAB_BOUND, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_BTN_TAB_HIDE, MF_UNCHECKED);
		break;
	}
	case DBG_BOUND:
	{
		CheckMenuItem(main_Menu, IDM_DBG_BTN_TAB_SHOW, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_BTN_TAB_BOUND, MF_CHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_BTN_TAB_HIDE, MF_UNCHECKED);
		break;
	}
	case DBG_HIDE:
	{
		CheckMenuItem(main_Menu, IDM_DBG_BTN_TAB_SHOW, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_BTN_TAB_BOUND, MF_UNCHECKED);
		CheckMenuItem(main_Menu, IDM_DBG_BTN_TAB_HIDE, MF_CHECKED);
		break;
	}
	}
}