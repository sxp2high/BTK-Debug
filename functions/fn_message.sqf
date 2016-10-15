/*
	File: fn_marker.sqf
	Author: sxp2high (BTK) (btk@arma3.cc)

	Description:
	Display GUI message.

	Parameter(s):
		0: STRING - text

	Returns:
	BOOLEAN - true when done

	Syntax:
	_shown = ["Hello world!"] call BTK_debug_fnc_message;
*/


private ["_text","_layer1","_layer2","_text1","_text2"];


// Dont show at mission start
if (time < 1) exitWith {};


// Parameter
_text = _this select 0;


// Register
_layer1 = ["btk_debug_message_layer_1"] call BIS_fnc_rscLayer;
_layer2 = ["btk_debug_message_layer_2"] call BIS_fnc_rscLayer;


// Clear
_layer1 cutText ["", "PLAIN"];
_layer2 cutText ["", "PLAIN"];


// Compile texts
_text1 = format["<t align='center' size='0.45' shadow='1' color='#d0d0d0' font='PuristaMedium'>DEBUG_</t>"];
_text2 = format["<t align='center' size='0.65' shadow='1' color='#ffffff' font='PuristaMedium'>%1</t>", _text];


// Display
[_text1, -1, (safezoneY + 0.55 * safezoneW), 7, 0.4, 0, _layer1] spawn BIS_fnc_dynamicText;
[_text2, -1, (safezoneY + 0.565 * safezoneW), 7, 0.4, 0, _layer2] spawn BIS_fnc_dynamicText;
playSound ["counter", true];


true