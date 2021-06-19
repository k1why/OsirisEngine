workspace "Osiris"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Osiris"
	location "Osiris"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/third-party/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OSIRIS_PLATFORM_WINDOWS",
			"OSIRIS_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "OSIRIS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OSIRIS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "OSIRIS_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Osiris/third-party/spdlog/include",
		"Osiris/src"
	}

	links
	{
		"Osiris"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OSIRIS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "OSIRIS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OSIRIS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "OSIRIS_DIST"
		optimize "On"
