// Wait for player
waitUntil {(isDedicated) || !(isNull player)};


// Variables
_addonTitle = "BTK Debug";
_addonVersion = "3.0.3";
_addonLink = "https://github.com/sxp2high/BTK-Debug";


// Require BTK Functions
waitUntil {!(isNil "btk_functions_init")};


// Already initialized?
if (!(isNil "btk_debug_init")) exitWith {};


// Userconfig
_loaded = false;


// Nothing found?
if (isNil {profileNamespace getVariable "btk_debug_config"}) then {

	profileNamespace setVariable ["btk_debug_config", true];

	profileNamespace setVariable ["btk_debug_enabled", true];
	profileNamespace setVariable ["btk_debug_keys", [219, 32]];
	profileNamespace setVariable ["btk_debug_mp_enabled", true];

	btk_debug_enabled = true;
	btk_debug_keys = [219, 32]; // Left Windows + D
	btk_debug_mp_enabled = true;

	_loaded = true;

} else {

	btk_debug_enabled = profileNamespace getVariable "btk_debug_enabled";
	btk_debug_keys = profileNamespace getVariable "btk_debug_keys";
	btk_debug_mp_enabled = profileNamespace getVariable "btk_debug_mp_enabled";

	_loaded = true;

};


// Make sure config is loaded
waitUntil {_loaded};


// No dedicated
if (isDedicated) exitWith { btk_debug_init = true; };


// Disabled?
if (!(btk_debug_enabled)) exitWith {};


// MP disabled?
if (isMultiplayer && !(btk_debug_mp_enabled)) exitWith {};


// Create background blur
btk_debug_background_blur = ppEffectCreate ["DynamicBlur", (160 + (round (random 99)))];
btk_debug_background_blur ppEffectEnable false;


// Dialog flow
[] spawn {

	// Loop
	while {true} do {

		// Keys match
		waitUntil {(btk_debug_keys call BTK_fnc_keyCheck)};

		// Dialog open?
		if (isNil "btk_debug_dialog_open") then {

			// Open
			btk_debug_dialog_open = true;
			[] call BTK_debug_fnc_dialog;

		} else {

			// Reset/close
			btk_debug_dialog_open = nil;

		};

		// Keys free or dead
		waitUntil {!(alive player) || !(btk_debug_keys call BTK_fnc_keyCheck)};

	};

};


// Note
[_addonTitle, _addonVersion, _addonLink, format["Open dialog  <font color='%1'>%2</font>", ([true] call BTK_fnc_usercolor), (btk_debug_keys call BTK_fnc_keyNames)]] call BTK_fnc_addonNote;


// Log
[format["%1 v%2 initialized!", _addonTitle, _addonVersion]] call BTK_fnc_log;


// Init flag
btk_debug_init = true;