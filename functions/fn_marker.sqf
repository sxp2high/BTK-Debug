/*
	File: fn_marker.sqf
	Author: sxp2high (BTK) (btk@arma3.cc)

	Description:
	Toggle tracking marker.

	Parameter(s):
		0: STRING - type ("player" or "group")

	Returns:
	BOOLEAN - true when done

	Syntax:
	_toggled = ["player"] call BTK_debug_fnc_marker;
*/


private ["_type","_toggle","_units","_index","_unitNames"];


// Parameter
_type = _this select 0;
_toggle = false;


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


// Get var
if ((isNil "btk_debug_marker_units") || (isNil "btk_debug_marker_init")) then { btk_debug_marker_units = []; btk_debug_marker_init = false; };
waitUntil {!(isNil "btk_debug_marker_units") && !(isNil "btk_debug_marker_init")};


// Delete
if (btk_debug_marker_init) exitWith {

	// Message
	[format["%1 deleteMarker;", _unitNames]] call BTK_debug_fnc_message;

	btk_debug_marker_units = [];
	btk_debug_marker_init = nil;

};


// All done
btk_debug_marker_init = true;


// Create marker
{

	_x spawn {

		_unit = _this;

		_marker = createMarkerLocal [(str(getPosATL (vehicle _unit)) + (name _unit)), (getPosATL (vehicle _unit))];
		_marker setMarkerShapeLocal "ICON";
		_marker setMarkerTypeLocal "mil_arrow2";
		_marker setMarkerColorLocal "ColorGUER";
		_marker setMarkerSizeLocal [0.4, 0.4];
		_marker setMarkerAlphaLocal 0.9;

		btk_debug_marker_units set [(count btk_debug_marker_units), _unit];

		while {(alive _unit) && ((count btk_debug_marker_units) > 0) && !(isNil "btk_debug_marker_init")} do {
			_marker setMarkerPosLocal (getPosATL (vehicle _unit));
			_marker setMarkerDirLocal (getDir (vehicle _unit));
			sleep 0.1;
		};

		sleep 1;
		if (_unit in btk_debug_marker_units) then { btk_debug_marker_units = btk_debug_marker_units - [_unit]; };
		deleteMarker _marker;

	};

} forEach _units;


// Message
[format["%1 createMarker;", _unitNames]] call BTK_debug_fnc_message;


true