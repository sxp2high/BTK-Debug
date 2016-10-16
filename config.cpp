class CfgPatches {

	class btk_debug {

		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Functions_F","A3_UI_F","btk_functions"};

		version = 1.0.0;
		versionStr = "1.0.0";
		versionAr[] = {1,0,0};

		author[] = {"sxp2high (BTK)"};
		authorUrl = "https://github.com/sxp2high/BTK-Debug";
	
		units[] = {};
		weapons[] = {};

	};

};


class cfgFunctions {

	#include "cfgFunctions.hpp"

};


#include "cfgDialog.hpp"