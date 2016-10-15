/*
	File: fn_setPos.sqf
	Author: sxp2high (BTK) (btk@arma3.cc)

	Description:
	Map click teleport.

	Parameter(s):
		0: STRING - type ("player", "vehicleplayer" or "group")

	Returns:
	BOOLEAN - true when done

	Syntax:
	_toggled = ["player"] call BTK_debug_fnc_setPos;
*/


private ["_type"];


// Parameter
_type = _this select 0;


// Spawn flow
[_type] spawn {

	_type = _this select 0;

	// Variables
	_playerVehicle = (vehicle player);
	_playerPos = (getPosATL _playerVehicle);
	_units = [];

	// Close dialog, open map
	closeDialog 0;
	openMap true;
	waitUntil {visibleMap};

	// Add handler
	onMapSingleClick "btk_debug_map_cick_pos = _pos;";

	// message
	[format["click on your map..."]] call BTK_debug_fnc_message;

	// Marker
	_markerCurrent = createMarkerLocal [str(_playerPos), _playerPos];
	_markerCurrent setMarkerShapeLocal "ICON";
	_markerCurrent setMarkerTypeLocal "hd_destroy";
	_markerCurrent setMarkerColorLocal "ColorWEST";
	_markerCurrent setMarkerSizeLocal [1.0, 1.0];
	_markerCurrent setMarkerDirLocal 45;

	// Wait for handler or map closed
	waitUntil {!(isNil "btk_debug_map_cick_pos") || !(visibleMap)};

	// Map closed
	if (isNil "btk_debug_map_cick_pos") exitWith {};

	// Marker
	_marker = createMarkerLocal [str(btk_debug_map_cick_pos), btk_debug_map_cick_pos];
	_marker setMarkerShapeLocal "ICON";
	_marker setMarkerTypeLocal "hd_destroy";
	_marker setMarkerColorLocal "ColorGUER";
	_marker setMarkerSizeLocal [1.2, 1.2];
	_marker setMarkerDirLocal 45;

	// Execute
	switch (_type) do {

		case ("player") : {
			_units set [(count _units), player];
			_pos = [(btk_debug_map_cick_pos select 0), (btk_debug_map_cick_pos select 1), (btk_debug_map_cick_pos select 2)];
			if (surfaceIsWater _pos) then { player setPosASL _pos; } else { player setPosATL _pos; };
		};

		case ("vehicleplayer") : {
			_units set [(count _units), player];
			_pos = [(btk_debug_map_cick_pos select 0), (btk_debug_map_cick_pos select 1), (btk_debug_map_cick_pos select 2)];
			if (surfaceIsWater _pos) then { _playerVehicle setPosASL _pos; } else { _playerVehicle setPosATL _pos; };
		};

		case ("group") : {

			_offSet = 1.1;

			{

				_units set [(count _units), _x];

				if (!(isPlayer _x)) then {

					_pos = player modelToWorld [-_offSet, 0, 0];
					_offSet = (_offSet + 1.1);
					if (surfaceIsWater _pos) then { _x setPosASL [(_pos select 0), (_pos select 1), (_pos select 2)]; } else { _x setPosATL [(_pos select 0), (_pos select 1), (_pos select 2)]; };
				
				} else {

					_pos = [(btk_debug_map_cick_pos select 0), (btk_debug_map_cick_pos select 1), (btk_debug_map_cick_pos select 2)];
					if (surfaceIsWater _pos) then { _x setPosASL _pos; } else { _x setPosATL _pos; };

				};

			} forEach (units (group player));

		};

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

	// Message
	[format["%1 setPos %2;", _unitNames, btk_debug_map_cick_pos]] call BTK_debug_fnc_message;

	// Reveal
	{ player reveal _x; } forEach (btk_debug_map_cick_pos nearEntities ["All", 50]);

	// Reset
	openMap false;

	// Destroy
	btk_debug_map_cick_pos = nil;

	// Delete marker
	sleep 10;
	deleteMarkerLocal _marker;
	deleteMarkerLocal _markerCurrent;

};


true