/*
	File: fn_freeze.sqf
	Author: sxp2high (BTK) (btk@arma3.cc)

	Description:
	Freeze/Unfreeze time (engine simulation).

	Parameter(s):
		-

	Returns:
	BOOLEAN - true when done

	Syntax:
	_freezed = [] call BTK_debug_fnc_freeze;
*/


private ["_display"];


// Need this for dialog
disableSerialization;


// Get display
_display = (uiNamespace getVariable "btk_debug_dialog_display");


// Toggle
if (isNil "btk_debug_freeze_on") then {

	btk_debug_freeze_on = true; // Flag

	(_display displayCtrl 1622) ctrlSetText format["U"];
	(_display displayCtrl 1622) ctrlSetTooltip format["Unfreeze Game"];

	setAccTime 0;

	[format["setAccTime 0;"]] call BTK_debug_fnc_message;

} else {

	btk_debug_freeze_on = nil; // Reset

	(_display displayCtrl 1622) ctrlSetText format["F"];
	(_display displayCtrl 1622) ctrlSetTooltip format["Freeze Game"];
	
	setAccTime 1;

	[format["setAccTime 1;"]] call BTK_debug_fnc_message;
	
};


true