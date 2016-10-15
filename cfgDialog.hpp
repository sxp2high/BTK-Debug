#define GUI_GRID_X	(0)
#define GUI_GRID_Y	(0)
#define GUI_GRID_W	(0.025)
#define GUI_GRID_H	(0.04)
#define GUI_GRID_WAbs	(1)
#define GUI_GRID_HAbs	(1)


/*
class RscText;
class IGUIBack;
class RscButton;
class RscEdit;
*/


class btk_debug_dialog {

    idd = -1;
    movingEnable = true;
	enableSimulation = true;
    onLoad = "uiNamespace setVariable ['btk_debug_dialog_display', (_this select 0)];";
	duration = 99999999;
	fadein = 0;
	fadeout = 1;

	class controls {

		class IGUIBack_2200: IGUIBack
		{
			idc = 2200;
			x = 1.5 * GUI_GRID_W + GUI_GRID_X;
			y = 4.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 8.5 * GUI_GRID_W;
			h = 8 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.6};
		};
		class IGUIBack_2201: IGUIBack
		{
			idc = 2201;
			x = 11 * GUI_GRID_W + GUI_GRID_X;
			y = 4.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 8.5 * GUI_GRID_W;
			h = 5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.6};
		};
		class IGUIBack_2202: IGUIBack
		{
			idc = 2202;
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 4.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 8.5 * GUI_GRID_W;
			h = 3.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.6};
		};
		class IGUIBack_2203: IGUIBack
		{
			idc = 2203;
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 9.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 8.5 * GUI_GRID_W;
			h = 3.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.6};
		};
		class IGUIBack_2204: IGUIBack
		{
			idc = 2204;
			x = 11 * GUI_GRID_W + GUI_GRID_X;
			y = 11 * GUI_GRID_H + GUI_GRID_Y;
			w = 8.5 * GUI_GRID_W;
			h = 3.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.6};
		};
		class IGUIBack_2205: IGUIBack
		{
			idc = 2205;
			x = 30 * GUI_GRID_W + GUI_GRID_X;
			y = 4.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 8.5 * GUI_GRID_W;
			h = 8 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.6};
		};
		class IGUIBack_2208: IGUIBack
		{
			idc = 2208;
			x = 1.5 * GUI_GRID_W + GUI_GRID_X;
			y = 16 * GUI_GRID_H + GUI_GRID_Y;
			w = 37 * GUI_GRID_W;
			h = 6 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.6};
		};
		class RscText_1000: RscText
		{
			idc = 1000;
			text = "Kill_";
			x = 1.5 * GUI_GRID_W + GUI_GRID_X;
			y = 3.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 8.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorText[] = {1,1,1,0.9};
			colorBackground[] = {0,0,0,0.8};
			sizeEx = 0.9 * GUI_GRID_H;
		};
		class button_kill_civilians: RscButton
		{
			idc = 1600;
			text = "Civilians";
			x = 2 * GUI_GRID_W + GUI_GRID_X;
			y = 5 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Kill all CIV within 500m";
			onButtonClick = "['units',civilian] call BTK_debug_fnc_kill;";
		};
		class button_kill_east: RscButton
		{
			idc = 1601;
			text = "East";
			x = 2 * GUI_GRID_W + GUI_GRID_X;
			y = 6.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Kill all EAST within 500m";
			onButtonClick = "['units',east] call BTK_debug_fnc_kill;";
		};
		class button_kill_guerilla: RscButton
		{
			idc = 1602;
			text = "Guerilla";
			x = 2 * GUI_GRID_W + GUI_GRID_X;
			y = 8 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Kill all GUER within 500m";
			onButtonClick = "['units',resistance] call BTK_debug_fnc_kill;";
		};
		class button_kill_west: RscButton
		{
			idc = 1603;
			text = "West";
			x = 2 * GUI_GRID_W + GUI_GRID_X;
			y = 9.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Kill all WEST within 500m";
			onButtonClick = "['units',west] call BTK_debug_fnc_kill;";
		};
		class button_kill_vehicles: RscButton
		{
			idc = 1604;
			text = "Vehicles";
			x = 2 * GUI_GRID_W + GUI_GRID_X;
			y = 11 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Destroy all vehicles within 50m";
			onButtonClick = "['vehicles',east] call BTK_debug_fnc_kill;";
		};
		class RscText_1001: RscText
		{
			idc = 1001;
			text = "Setpos_";
			x = 11 * GUI_GRID_W + GUI_GRID_X;
			y = 3.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 8.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorText[] = {1,1,1,0.9};
			colorBackground[] = {0,0,0,0.8};
			sizeEx = 0.9 * GUI_GRID_H;
		};
		class button_setpos_vehicle: RscButton
		{
			idc = 1606;
			text = "Vehicle";
			x = 11.5 * GUI_GRID_W + GUI_GRID_X;
			y = 5 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Setpos player vehicle (map click)";
			onButtonClick = "['vehicleplayer'] call BTK_debug_fnc_setPos;";
		};
		class button_setpos_player: RscButton
		{
			idc = 1605;
			text = "Player";
			x = 11.5 * GUI_GRID_W + GUI_GRID_X;
			y = 6.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Setpos player (map click)";
			onButtonClick = "['player'] call BTK_debug_fnc_setPos;";
		};
		class button_setpos_playergroup: RscButton
		{
			idc = 1607;
			text = "Player Group";
			x = 11.5 * GUI_GRID_W + GUI_GRID_X;
			y = 8 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Setpos player group (map click)";
			onButtonClick = "['group'] call BTK_debug_fnc_setPos;";
		};
		class RscText_1004: RscText
		{
			idc = 1004;
			text = "Marker_";
			x = 11 * GUI_GRID_W + GUI_GRID_X;
			y = 10 * GUI_GRID_H + GUI_GRID_Y;
			w = 8.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorText[] = {1,1,1,0.9};
			colorBackground[] = {0,0,0,0.8};
			sizeEx = 0.9 * GUI_GRID_H;
		};
		class button_marker_player: RscButton
		{
			idc = 1612;
			text = "Player";
			x = 11.5 * GUI_GRID_W + GUI_GRID_X;
			y = 11.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Toggle marker for player";
			onButtonClick = "['player'] call BTK_debug_fnc_marker;";
		};
		class button_marker_playergroup: RscButton
		{
			idc = 1613;
			text = "Player Group";
			x = 11.5 * GUI_GRID_W + GUI_GRID_X;
			y = 13 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Toggle marker for player group";
			onButtonClick = "['group'] call BTK_debug_fnc_marker;";
		};
		class RscText_1002: RscText
		{
			idc = 1002;
			text = "Setcaptive_";
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 3.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 8.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorText[] = {1,1,1,0.9};
			colorBackground[] = {0,0,0,0.8};
			sizeEx = 0.9 * GUI_GRID_H;
		};
		class button_captive_player: RscButton
		{
			idc = 1608;
			text = "Player";
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 5 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Toggle setcaptive for player";
			onButtonClick = "['player'] call BTK_debug_fnc_setCaptive;";
		};
		class button_captive_playergroup: RscButton
		{
			idc = 1609;
			text = "Player Group";
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 6.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Toggle setcaptive for player group";
			onButtonClick = "['group'] call BTK_debug_fnc_setCaptive;";
		};
		class RscText_1003: RscText
		{
			idc = 1003;
			text = "Allowdamage_";
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 8.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 8.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorText[] = {1,1,1,0.9};
			colorBackground[] = {0,0,0,0.8};
			sizeEx = 0.9 * GUI_GRID_H;
		};
		class button_allowdamage_player: RscButton
		{
			idc = 1610;
			text = "Player";
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 10 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Toggle allowdamage for player";
			onButtonClick = "['player'] call BTK_debug_fnc_allowDamage;";
		};
		class button_allowdamage_playergroup: RscButton
		{
			idc = 1611;
			text = "Player Group";
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 11.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Toggle allowdamage for player group";
			onButtonClick = "['group'] call BTK_debug_fnc_allowDamage;";
		};
		class RscText_1005: RscText
		{
			idc = 1005;
			text = "Copy_";
			x = 30 * GUI_GRID_W + GUI_GRID_X;
			y = 3.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 8.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorText[] = {1,1,1,0.9};
			colorBackground[] = {0,0,0,0.8};
			sizeEx = 0.9 * GUI_GRID_H;
		};
		class button_copy_player: RscButton
		{
			idc = 1614;
			text = "Player";
			x = 30.5 * GUI_GRID_W + GUI_GRID_X;
			y = 5 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Copy position, direction, and animation of player";
			onButtonClick = "['player'] call BTK_debug_fnc_copy;";
		};
		class button_copy_cursortarget: RscButton
		{
			idc = 1615;
			text = "Cursor Target";
			x = 30.5 * GUI_GRID_W + GUI_GRID_X;
			y = 6.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Copy class, position and direction of cursor target";
			onButtonClick = "['cursortarget'] call BTK_debug_fnc_copy;";
		};
		class button_copy_nearestobjects: RscButton
		{
			idc = 1616;
			text = "Nearest objects";
			x = 30.5 * GUI_GRID_W + GUI_GRID_X;
			y = 8 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Copy class names of all objects within 25m";
			onButtonClick = "['nearestobjects'] call BTK_debug_fnc_copy;";
		};
		class button_copy_nearobjects: RscButton
		{
			idc = 1620;
			text = "Near objects";
			x = 30.5 * GUI_GRID_W + GUI_GRID_X;
			y = 9.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Copy class names of all near objects within 25m";
			onButtonClick = "['nearobjects'] call BTK_debug_fnc_copy;";
		};
		class button_copy_nearentities: RscButton
		{
			idc = 1621;
			text = "Near entities";
			x = 30.5 * GUI_GRID_W + GUI_GRID_X;
			y = 11 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Copy class names of all entities within 25m";
			onButtonClick = "['nearentities'] call BTK_debug_fnc_copy;";
		};
		class header_menu: RscText
		{
			idc = 1006;
			text = "BTK DEBUG_";
			x = 1.5 * GUI_GRID_W + GUI_GRID_X;
			y = 1 * GUI_GRID_H + GUI_GRID_Y;
			w = 37 * GUI_GRID_W;
			h = 2 * GUI_GRID_H;
			colorText[] = {1,1,1,0.9};
			colorBackground[] = {0,0,0,0.8};
			sizeEx = 1.35 * GUI_GRID_H;
		};
		class header_console: RscText
		{
			idc = 1007;
			text = "Console_";
			x = 1.5 * GUI_GRID_W + GUI_GRID_X;
			y = 15 * GUI_GRID_H + GUI_GRID_Y;
			w = 37 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorText[] = {1,1,1,0.9};
			colorBackground[] = {0,0,0,0.8};
			sizeEx = 1 * GUI_GRID_H;
		};
		class RscEdit_1400: RscEdit
		{
			idc = 1400;
			style=16;
			autocomplete = "scripting";
			x = 2 * GUI_GRID_W + GUI_GRID_X;
			y = 16.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 31.5 * GUI_GRID_W;
			h = 5 * GUI_GRID_H;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
			//colorSelection[] = {0.6,0.6,0.6,1};
			sizeEx = 0.85 * GUI_GRID_H;
		};
		class button_console_local: RscButton
		{
			idc = 1617;
			text = "Local";
			x = 34 * GUI_GRID_W + GUI_GRID_X;
			y = 16.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 4 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Execute local";
			onButtonClick = "['local'] call BTK_debug_fnc_exec;";
		};
		class button_console_global: RscButton
		{
			idc = 1618;
			text = "Global";
			x = 34 * GUI_GRID_W + GUI_GRID_X;
			y = 18 * GUI_GRID_H + GUI_GRID_Y;
			w = 4 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 0.85 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Execute global";
			onButtonClick = "['global'] call BTK_debug_fnc_exec;";
		};
		class button_x: RscButton
		{
			idc = 1619;
			text = "X";
			x = 36.5 * GUI_GRID_W + GUI_GRID_X;
			y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 1.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 1 * GUI_GRID_H;
			colorText[] = {1,1,1,0.9};
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "Close (ESC)";
			onButtonClick = "closeDialog 0;";
		};
		class RscButton_1622: RscButton
		{
			idc = 1622;
			text = "F";
			x = 34.5 * GUI_GRID_W + GUI_GRID_X;
			y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 1.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			sizeEx = 1 * GUI_GRID_H;
			colorText[] = {1,1,1,0.9};
			colorBackground[] = {0,0,0,0.9};
			colorBackgroundActive[] = {"(profilenamespace getVariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getVariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getVariable ['GUI_BCG_RGB_B',0.8862])", 0.9};
			tooltip = "setAccTime 0";
			onButtonClick = "[] call BTK_debug_fnc_freeze;";
		};

	};

};