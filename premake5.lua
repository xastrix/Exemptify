local global = "Exemptify"

workspace (global)
    configurations { "Debug", "Release" }
    platforms { "x64", "x86" }

project (global)
    kind "ConsoleApp"
	language "C++"

	targetdir "bin/%{cfg.buildcfg}"
	objdir "obj/%{cfg.buildcfg}"

	files { "*.cpp", "*.h" }

	buildoptions { "/std:c++latest" }

	characterset "MBCS"
	warnings "Off"
	optimize "Size"