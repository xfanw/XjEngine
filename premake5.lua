workspace "Xj"
	architecture "x64"
	
	
	
	configurations{
		"Debug",
		"Release",
		"Dist"
	}
	startproject  "Game"

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
-- Include direcrories relative to root folder (solution directory)
	IncludeDir  = {}
	IncludeDir["GLFW"] = "Xj/vender/glfw/include"
	IncludeDir["GLAD"] = "Xj/vender/glad/include"
	IncludeDir["ImGui"] = "Xj/vender/imgui"
	--IncludeDir["GLM"] = "Xj/vender/glm"
group "Dependencies"
	include "Xj/vender/glfw"
	include "Xj/vender/glad"
	include "Xj/vender/imgui"
	--include "Xj/vender/glm"
group ""

project "Xj"
		location "Xj"
		kind "StaticLib"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"
		warnings "Extra"
		
		-- targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		-- objdir("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "xjpch.h"
		pchsource "Xj/src/xjpch.cpp"

		files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp",
			-- ++
			"%{prj.name}/vender/glm/glm/**.hpp",
			"%{prj.name}/vender/glm/glm/**.inl",
			
			-- "%{prj.name}/vender/imgui/examples/**.h" ,
			-- "%{prj.name}/vender/imgui/examples/**.cpp" 
		}

		includedirs{
			"%{prj.name}/src",
			"%{prj.name}/vender/spdlog/include" ,
			--"%{prj.name}/vender/imgui/examples" ,
			"%{IncludeDir.GLFW}",
			"%{IncludeDir.GLAD}",
			"%{IncludeDir.ImGui}",
			--"%{IncludeDir.GLM}"
		}
		
		links{
			"GLFW",
			"GLAD",
			"ImGui",
			--"GLM",
			"opengl32.lib"
		}

		defines{
			"_CRT_SECURE_NO_WARNINGS"
		}
		filter "system:windows"
			systemversion "latest"

			defines{
				"XJ_PLATFORM_WINDOWS",
				"XJ_BUILD_DLL",				
			}

			-- Frank(26) change to static lib
			-- postbuildcommands{
				-- ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Game/\"")
			-- }

		filter "configurations:Debug"
			defines "XJ_DEBUG"
			defines "XJ_ENABLE_ASSERT"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "XJ_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "XJ_DIST"
			runtime "Release"
			optimize "on"

project "Game"
	location "Game"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	warnings "Extra"
	
	targetdir ("bin/" ..outputdir .. "/%{prj.name}")
	objdir("bin-int/" ..outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"Xj/vender/spdlog/include",
		"Xj/vender/imgui",
		"Xj/vender/glm",
		"Xj/src"
	}

	links{
		"Xj",
		"ImGui"
	}
	filter "system:windows"
		systemversion "latest"

		defines{
			"XJ_PLATFORM_WINDOWS"					
		}

	filter "configurations:Debug"
		defines "XJ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "XJ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "XJ_DIST"
		runtime "Release"
		optimize "on"