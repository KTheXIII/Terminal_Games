project "Terminal"
  kind "StaticLib"
  language "C++"
  cppdialect "C++17"

  targetdir ("bin/" .. outdir .. "/%{prj.name}")
  objdir ("obj/" .. outdir .. "/%{prj.name}")

  files {
    "src/**.h",
    "src/**.hpp",
    "src/**.cpp"
  }

  filter "configurations:Debug"
    runtime "Debug"
    symbols "on"

  filter "configurations:Release"
    runtime "Release"
    optimize "on"