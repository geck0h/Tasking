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

    files 
    { 
        "%{prj.name}/src/*.cpp",
        "%{prj.name}/src/*.h",
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


