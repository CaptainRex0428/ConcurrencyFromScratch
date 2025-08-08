include "Directory.lua"
include "Dependencies.lua"

workspace "ConcurrencyFromScratch"
	architecture "x64"
	startproject "EntryProject"
	configurations
	{
		"Debug",
		"Release",
        "Dist"
	}

    filter "system:windows"
    buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus","/utf-8" }
	

group ""
	include "Template01.lua"
	include "Template02.lua"
	include "Template03.lua"
	include "Template04.lua"
	include "Template05.lua"
	include "Template06.lua"