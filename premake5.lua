workspace "Tasking" 
    configurations { "Debug", "Release" }
    platforms { "x64" }
    language "C++" 
    cppdialect "C++17" 

outputdir = "%{cfg.platform}/%{cfg.buildcfg}"

project "Tasking" 
    kind "ConsoleApp" 
    location "Tasking"

    targetdir ( "bin/" .. outputdir )
    objdir ( "bin/int/" .. outputdir )

    includedirs
    {
        "%{wks.location}/dep/GLFW/include"
    }

    files 
    { 
        "%{prj.name}/src/*.cpp",
        "%{prj.name}/src/*.h",
    }

    libdirs 
    {
        "%{wks.location}/dep/GLFW/lib-vc2022"
    }

    links
    {
        "opengl32.lib",
        "glfw3.lib"
    }

    filter { "platforms:x64", "configurations:Debug" }
        system "Windows"
        defines { "DEBUG" }
        runtime "Debug"
        optimize "Debug"

    filter { "platforms:x64", "configurations:Release" }
        system "Windows"
        defines { "NDEBUG" }
        runtime "Release"
        optimize "Speed"


