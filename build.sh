#!/bin/bash
if [ "$1" == "" ]; then
  printf "Usage: $0 <name of cpp file with no extension>\n"
  exit 1
fi

# ImGui path
imgui=./imgui

g++ -I $imgui -I $imgui/backends/ $1.cpp imgui_interface.cpp $imgui/imgui{_draw,_tables,_widgets,}.cpp $imgui/backends/imgui_impl_glfw.cpp $imgui/backends/imgui_impl_opengl3.cpp -lGL -lglfw -o $1