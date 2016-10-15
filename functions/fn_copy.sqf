/*
	File: fn_copy.sqf
	Author: sxp2high (BTK) (btk@arma3.cc)

	Description:
	copyToClipboard various data.

	Parameter(s):
		0: STRING - type (possible values: "player", "cursortarget", "nearestobjects", "nearobjects", "nearentities")

	Returns:
	BOOLEAN - true when done

	Syntax:
	_copied = ["player"] call BTK_debug_fnc_copy;
*/


private ["_type","_data"];


// Parameter
_type = _this select 0;
_data = "";


// Execute
switch (_type) do {

	case ("player") : {

		_data = str[(getPosATL (vehicle player)), (getDir (vehicle player)), (animationState player)];
		copyToClipboard _data;

	};

	case ("cursortarget") : {

		_data = str[(typeOf cursorTarget), (getPosATL cursorTarget), (getDir cursorTarget), (animationState player)];
		copyToClipboard _data;

	};

	case ("nearestobjects") : {

		_data = [];
		{ _data set [(count _data), (typeOf _x)]; } forEach (nearestObjects [player, ["all"], 25]);
		copyToClipboard str(_data);

	};

	case ("nearobjects") : {

		_data = [];
		{ _data set [(count _data), (typeOf _x)]; } forEach ((getPosATL player) nearObjects 25);
		copyToClipboard str(_data);

	};

	case ("nearentities") : {

		_data = [];
		{ _data set [(count _data), (typeOf _x)]; } forEach ((getPosATL player) nearEntities ["All", 25]);
		copyToClipboard str(_data);

	};

};


[format["copy %1", _data]] call BTK_debug_fnc_message;


true