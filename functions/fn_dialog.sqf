/*
	File: fn_dialog.sqf
	Author: sxp2high (BTK) (btk@arma3.cc)

	Description:
	Opens the debug dialog.

	Parameter(s):
		-

	Returns:
	BOOLEAN - true when open

	Syntax:
	_dialog = [] call BTK_debug_fnc_dialog;
*/


private ["_dialog"];


// Clear keys, just in case
btk_keys_current = [];


// Just in case
if (!(alive player) || !(local player)) exitWith {};


// Anim
//if (((vehicle player) == player) && ((animationState player) !="amovpsitmstpslowwrfldnon") && ((animationState player) !="amovpercmstpsraswrfldnon_salute")) then { player playActionNow "Gear"; };


// Close previous dialog
if (dialog) then { closeDialog 0; };


// Create dialog
disableSerialization;
_dialog = createDialog "btk_debug_dialog";


// Dialog open
waitUntil {_dialog};
_display = (uiNamespace getVariable "btk_debug_dialog_display");


// Freeze button
(_display displayCtrl 1622) ctrlSetTooltip format["Freeze Game"];


// Set last code
if (!(isNil {profileNamespace getVariable "btk_debug_exec_last"})) then { ctrlSetText [1400, (profileNamespace getVariable "btk_debug_exec_last")]; };


// Reset dialog
[] spawn {

	// Dialog open
	waitUntil {(dialog)};

	// Blur background
	btk_debug_background_blur ppEffectEnable true;
	btk_debug_background_blur ppEffectAdjust [0.35];
	btk_debug_background_blur ppEffectCommit 1;

	// Dialog closed or died
	waitUntil {!(dialog) || !(alive player) || (isNil "btk_debug_dialog_open")};

	// Reset
	if (dialog) then { closeDialog 0; };
	btk_debug_dialog_open = nil;

	// Fade out blur
	btk_debug_background_blur ppEffectAdjust [0];
	btk_debug_background_blur ppEffectCommit 0.5;

};


true