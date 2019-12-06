workspace "Xj"
	architecture "x64"
	
	configurations{
		"Debug",
		"Release",
		"Dist"
	}
	
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Xj"
		location "Xj"
		kind "SharedLib"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir("bin-int/" .. outputdir .. "/%{prj.name}")

		files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs{
			"%{prj.name}/vender/spdlog/include" 
		}



		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "10.0.18362.0"

			defines{
				"XJ_PLATFORM_WINDOWS",
				"XJ_BUILD_DLL"							
			}


			postbuildcommands{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Game")
			}

		filter "configurations:Debug"
			defines "XJ_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "XJ_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "XJ_DIST"
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
			systemversion "10.0.18362.0"

			defines{
				"XJ_PLATFORM_WINDOWS"					
			}

		filter "configurations:Debug"
			defines "XJ_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "XJ_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "XJ_DIST"
			optimize "On"