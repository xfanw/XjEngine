workspace "Xj"
	architecture "x64"
	
	configurations{
		"Debug",
		"Release",
		"Dist"
	}
	
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
-- Include direcrories relative to root folder (solution directory)
	IncludeDir  = {}
	IncludeDir["GLFW"] = "Xj/vender/GLFW/include"
	
	include "Xj/vender/GLFW"
project "Xj"
		location "Xj"
		kind "SharedLib"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "xjpch.h"
		pchsource "Xj/src/xjpch.cpp"

		files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs{
			"%{prj.name}/src",
			"%{prj.name}/vender/spdlog/include" ,
			"%{IncludeDir.GLFW}"
		}
		
		links{
			"GLFW",
			"opengl32.lib"
		}


		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			defines{
				"XJ_PLATFORM_WINDOWS",
				"XJ_BUILD_DLL"							
			}


			postbuildcommands{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Game")
			}

		filter "configurations:Debug"
			defines "XJ_DEBUG"
			defines "XJ_ENABLE_ASSERT"
			buildoptions "/MDd"
			symbols "On"

		filter "configurations:Release"
			defines "XJ_RELEASE"
			buildoptions "/MD"
			optimize "On"

		filter "configurations:Dist"
			defines "XJ_DIST"
			buildoptions "/MD"
			optimize "On"

project "Game"
	location "Game"
		kind "ConsoleApp"
		language "C++"

		targetdir ("bin/" ..outputdir .. "/%{prj.name}")
		objdir("bin-int/" ..outputdir .. "/%{prj.name}")

		files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs{
			"Xj/vender/spdlog/include",
			"Xj/src"
		}

		links{
			"Xj"
		}
		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			defines{
				"XJ_PLATFORM_WINDOWS"					
			}

		filter "configurations:Debug"
			defines "XJ_DEBUG"
			buildoptions "/MDd"
			symbols "On"

		filter "configurations:Release"
			defines "XJ_RELEASE"
			buildoptions "/MD"
			optimize "On"

		filter "configurations:Dist"
			defines "XJ_DIST"
			buildoptions "/MD"
			optimize "On"