/*
	File: fn_allowDamage.sqf
	Author: sxp2high (BTK) (btk@arma3.cc)

	Description:
	Toggle allowDamage using handledamage eventhandler.

	Parameter(s):
		0: STRING - type ("player" or "group")

	Returns:
	BOOLEAN - true when done

	Syntax:
	_toggled = ["player"] call BTK_debug_fnc_allowDamage;
*/


private ["_type","_protected","_units","_index","_unitNames","_unitNames"];


// Parameter
_type = _this select 0;
_protected = false;


// Get units
_units = switch (_type) do {
	case ("player") : { [player]; };
	case ("group") : { (units (group player)); };
};


// Names
_index = 0;
_unitNames = "";


// Compile names
{

	_index = _index + 1;

	if (_index == (count _units)) then {
		_unitNames = _unitNames + (name _x);
	} else {
		_unitNames = _unitNames + (name _x) + ", ";
	};

} forEach _units;


// Execute
{

	private ["_unit","_isProtected","_eh"];

	_unit = _x;

	_isProtected = if (isNil {_unit getVariable "btk_debug_allowdamage"}) then { false; } else { true; };

	if (_isProtected) then {
		_protected = true;
		_eh = _unit getVariable "btk_debug_allowdamage";
		_unit removeEventHandler ["HandleDamage", _eh];
		_unit setVariable ["btk_debug_allowdamage", nil, false];
	} else {
		_protected = false;
		_eh = _unit addEventHandler ["HandleDamage", { false; }];
		_unit setVariable ["btk_debug_allowdamage", _eh, false];
	};

} forEach _units;


// Message
[format["%1 allowDamage %2;", _unitNames, _protected]] call BTK_debug_fnc_message;


true