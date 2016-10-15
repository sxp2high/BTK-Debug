/*
	File: fn_setCaptive.sqf
	Author: sxp2high (BTK) (btk@arma3.cc)

	Description:
	Toggle setCaptive.

	Parameter(s):
		0: STRING - type ("player" or "group")

	Returns:
	BOOLEAN - true when done

	Syntax:
	_toggled = ["player"] call BTK_debug_fnc_setCaptive;
*/


private ["_type","_captive","_units","_index","_unitNames"];


// Parameter
_type = _this select 0;
_captive = true;


// Get units
_units = switch (_type) do {
	case ("player") : { [player]; };
	case ("group") : { (units (group player)); };
};


// Names
_index = 0;
_unitNames = "";

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

	private ["_unit","_var"];

	_unit = _x;

	if (captive _unit) then {
		_captive = false;
		_unit setCaptive false;
	} else {
		_captive = true;
		_unit setCaptive true;
	};

} forEach _units;


// Message
[format["%1 setCaptive %2;", _unitNames, _captive]] call BTK_debug_fnc_message;


true