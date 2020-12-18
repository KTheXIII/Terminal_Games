workspace "TerminalGames"
  architecture "x64"

  startproject "Test"

  configurations {
    "Debug",
    "Release",
    "Dist"
  }

outdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

indirs = {}
indirs["Terminal"] = "Terminal/src"

group "Dependencies"
  include "Terminal/premake5.terminal.lua"
group ""

project "Test"
  location "Test"
  kind "ConsoleApp"
  language "C++"
  staticruntime "on"
  cppdialect "C++17"

  targetdir("bin/" ..outdir.. "/%{prj.name}")
  objdir("obj/" ..outdir.. "/%{prj.name}")

  files {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp",
  }

  includedirs {
    "%{prj.name}/src",
    "%{indirs.Terminal}"
  }

  links {
    "Terminal"
  }
  
  filter "system:macosx"
    systemversion "latest"
    system "macosx"
  
  filter "system:linux"
    system "linux"
    systemversion "latest"
  
  filter "system:Windows"
    system "Windows"
    systemversion "latest"

  filter "configurations:Debug"
    symbols "On"

  filter "configurations:Release"
    optimize "On"

  filter "configurations:Dist"
    optimize "On"

project "RockPaperScissor"
  location "RockPaperScissor"
  kind "ConsoleApp"
  language "C++"
  staticruntime "on"
  cppdialect "C++17"

  targetdir("bin/" ..outdir.. "/%{prj.name}")
  objdir("obj/" ..outdir.. "/%{prj.name}")

  files {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp",
  }

  includedirs {
    "%{prj.name}/src",
    "%{indirs.Terminal}"
  }

  links {
    "Terminal"
  }
  
  filter "system:macosx"
    systemversion "latest"
    system "macosx"
  
  filter "system:linux"
    system "linux"
    systemversion "latest"
  
  filter "system:Windows"
    system "Windows"
    systemversion "latest"

  filter "configurations:Debug"
    symbols "On"

  filter "configurations:Release"
    optimize "On"

  filter "configurations:Dist"
    optimize "On"

project "Gomoku"
  location "Gomoku"
  kind "ConsoleApp"
  language "C++"
  staticruntime "on"
  cppdialect "C++17"

  targetdir("bin/" ..outdir.. "/%{prj.name}")
  objdir("obj/" ..outdir.. "/%{prj.name}")

  files {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp",
  }

  includedirs {
    "%{prj.name}/src",
    "%{indirs.Terminal}"
  }

  links {
    "Terminal"
  }
  
  filter "system:macosx"
    systemversion "latest"
    system "macosx"
  
  filter "system:linux"
    system "linux"
    systemversion "latest"
  
  filter "system:Windows"
    system "Windows"
    systemversion "latest"

  filter "configurations:Debug"
    symbols "On"

  filter "configurations:Release"
    optimize "On"

  filter "configurations:Dist"
    optimize "On"

project "ConnectFour"
  location "ConnectFour"
  kind "ConsoleApp"
  language "C++"
  staticruntime "on"
  cppdialect "C++17"

  targetdir("bin/" ..outdir.. "/%{prj.name}")
  objdir("obj/" ..outdir.. "/%{prj.name}")

  files {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp",
  }

  includedirs {
    "%{prj.name}/src",
    "%{indirs.Terminal}"
  }

  links {
    "Terminal"
  }
  
  filter "system:macosx"
    systemversion "latest"
    system "macosx"
  
  filter "system:linux"
    system "linux"
    systemversion "latest"
  
  filter "system:Windows"
    system "Windows"
    systemversion "latest"

  filter "configurations:Debug"
    symbols "On"

  filter "configurations:Release"
    optimize "On"

  filter "configurations:Dist"
    optimize "On"