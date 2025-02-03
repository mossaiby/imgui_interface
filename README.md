# imgui_interface

 A very light `ImGui` wrapper

 If you need a simple `ImGui` wrapper for your code that frees you from writing boilerplate code, `imgui_interface` is for you. It only provides three functions:

```c++
bool imgui_init(int width, int height, const char* title);
bool imgui_loop(std::function<void()> user_renderer, std::initializer_list<float> background_color = { 0.1f, 0.1f, 0.1f });
void imgui_cleanup();
```

## Dependencies

The current version uses `GLFW` and `OpenGL 3`, hence the corresponding headers and libraries must be installed. `init.sh` can be used to clone `ImGui` from GitHub. `build.sh` can be used to compile your project using `g++`.

## Getting started

To add `ImGui` to your code, just do the following:

1. `#include "imgui_interface.hpp"`
2. In the initialization part of your code, call `imgui_init(width, height, title)`
3. Write your renderer logic inside a lambda (or equivalents) and pass it to `imgui_loop(user_renderer, { r, g, b })` where `{ r, g, b }` is the color code of the window background.
4. To clean things up, call `imgui_cleanup()`.

## Other backends

The current configuration uses `GLFW`/`OpenGL 3` backend. To use other backends, install the requirements and change `imgui_interface.hpp` and `imgui_interface.cpp` based on `ImGui`'s documentation.

## Examples

To build and run the examples, run `init.sh` once to clone `ImGui` and then use the following commands to build the examples:

```shell
$ ./build.sh example-1
$ ./build.sh example-2
```