workspace "Tasking" 
    configurations { "DebugMINGW", "ReleaseMINGW", "DebugMSVC", "ReleaseMSVC" }
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
        "%{prj.name}/src/",
        "%{wks.location}/dep/GLFW/include/",
        "%{wks.location}/dep/GLEW/include/"
    }

    files 
    { 
        "%{prj.name}/src/*.cpp",
        "%{prj.name}/src/*.h"
    }

    libdirs 
    {
        "%{wks.location}/dep/GLFW/lib-vc2022",
        "%{wks.location}/dep/GLFW/lib-mingw-w64",
        "%{wks.location}/dep/GLEW/lib/Release/x64"
    }

    -- TODO: compile glew for MINGW
    filter { "configurations:DebugMINGW or ReleaseMINGW" }
        links
        {
            "opengl32",
            "libglfw3",
            "glew32s",
            "gdi32"
        }
    
    filter { "configurations:DebugMSVC or ReleaseMSVC" }
        links
        {
            "opengl32.lib",
            "glfw3.lib",
            "glew32s.lib",
            "gdi32.lib"
        }

    filter {}

    filter { "platforms:x64", "configurations:DebugMSVC", "configurations:DebugMINGW" }
        system "Windows"
        defines { "DEBUG" }
        runtime "Debug"
        optimize "Debug"

    filter { "platforms:x64", "configurations:ReleaseMSVC", "configurations:ReleaseMINGW" }
        system "Windows"
        defines { "NDEBUG" }
        runtime "Release"
        optimize "Speed"

    filter{}


