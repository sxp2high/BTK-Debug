class btk_debug {

	tag = "BTK_debug";

	class Init {

		class init { file = "btk_debug\init.sqf"; postInit = 1; }; // BTK_debug_fnc_init

	};

	class Functions {

		file = "btk_debug\functions";

		class allowDamage { description = "Toggle allowDamage using handledamage eventhandler."; }; // BTK_debug_fnc_allowDamage
		class copy { description = "copyToClipboard various data."; }; // BTK_debug_fnc_copy
		class dialog { description = "Opens the debug dialog."; }; // BTK_debug_fnc_dialog
		class exec { description = "Execute console code."; }; // BTK_debug_fnc_exec
		class freeze { description = "Freeze/Unfreeze time (engine simulation)."; }; // BTK_debug_fnc_freeze
		class kill { description = "Kill/destroy the objects in the area."; }; // BTK_debug_fnc_kill
		class marker { description = "Toggle tracking marker."; }; // BTK_debug_fnc_marker
		class message { description = "Display GUI message."; }; // BTK_debug_fnc_message
		class setCaptive { description = "Toggle setCaptive."; }; // BTK_debug_fnc_setCaptive
		class setPos { description = "Map click teleport."; }; // BTK_debug_fnc_setPos

	};

};