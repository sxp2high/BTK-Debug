/*
	File: fn_exec.sqf
	Author: sxp2high (BTK) (btk@arma3.cc)

	Description:
	Execute console code.

	Parameter(s):
		0: STRING - type ("global" or "local")

	Returns:
	BOOLEAN - true when done

	Syntax:
	_executed = ["local"] call BTK_debug_fnc_exec;
*/


private ["_type","_code"];


// Parameter
_type = _this select 0;


// Get and set rscedit
_code = ctrlText 1400;
btk_debug_exec_last = _code;
profileNamespace setVariable ["btk_debug_exec_last", _code];


// Execute
switch (_type) do {

	// Global
	case ("global") : {
		btk_debug_mp_exec_code = (compile (format["%1", _code])); publicVariable "btk_debug_mp_exec_code";
		[btk_debug_mp_exec_code, "BIS_fnc_spawn", nil, false] call BIS_fnc_MP;
	};

	// Local
	case ("local") : {
		[] spawn (compile (format["%1", _code]));
	};

};


// Message
[format["%1", _code]] call BTK_debug_fnc_message;


true