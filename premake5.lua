workspace "Pong"
    configurations { "Debug", "Release" }

project "Pong"
    kind "ConsoleApp"
    language "C"
    targetdir "bin/%{cfg.buildcfg}"

    files { "./src/**.h", "./src/**.c" }

    includedirs { "./vendor/raylib/include" }
    libdirs { "./vendor/raylib/lib" }
    links {
        "raylib",
        "m"
    }


    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
    
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"