/*
	File: fn_kill.sqf
	Author: sxp2high (BTK) (btk@arma3.cc)

	Description:
	Kill/destroy the objects in the area.

	Parameter(s):
		0: STRING - type ("units" or "vehicles")
		1: SIDE - side

	Returns:
	BOOLEAN - true when done

	Syntax:
	_killed = ["units", east] call BTK_debug_fnc_kill;
*/


private ["_type","_side"];


// Parameter
_type = _this select 0;
_side = _this select 1;


// Execute
switch (_type) do {

	// Men
	case ("units") : {

		private ["_men","_crew","_allMen","_allVehicles"];

		_men = [];
		_crew = [];

		_allMen = (getPosATL player) nearEntities [["Man"], 500];
		_allVehicles = (getPosATL player) nearEntities [["LandVehicle", "Air", "Ship", "Tank"], 500];

		// Infantry
		if ((count _allMen) > 0) then {

			{
				if (((side _x) == _side) && !(isPlayer _x) && !(_x isKindOf "Animal")) then { _men = (_men + [_x]); };
			} forEach _allMen;
			if ((count _men) > 0) then { { _x setDamage 1; } forEach _men; };

		};

		// Crew
		if ((count _allVehicles) > 0) then {

			{
				if (({(side _x) == _side} count crew _x) > 0) then {
					_crew = (_crew + (crew _x));
				};
			} forEach _allVehicles;

			if ((count _crew) > 0) then { { _x setDamage 1; } forEach _crew; };

		};

		// Message
		if ((count _crew) > 0) then {
			[format["killed %1 men (%2 crewmen);", (count _men), (count _crew)]] call BTK_debug_fnc_message;
		
		} else {
			[format["killed %1 men;", (count _men), (count _crew)]] call BTK_debug_fnc_message;
		};

	};

	// Vehicles
	case ("vehicles") : {

		private ["_vehicles","_allVehicles"];

		_vehicles = [];
		_allVehicles = (getPosATL player) nearEntities [["LandVehicle", "Air", "Ship", "Tank"], 50];

		if ((count _allVehicles) > 0) then {

			{
				_vehicles = (_vehicles + [_x]);
			} forEach _allVehicles;
			if ((count _vehicles) > 0) then { { _x setDamage 1; } forEach _vehicles; };

		};

		// Message
		[format["killed %1 vehicles;", (count _vehicles)]] call BTK_debug_fnc_message;

	};

};


true