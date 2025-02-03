#pragma once

#include <functional>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

bool imgui_init(int width, int height, const char* title);
bool imgui_loop(std::function<void()> user_renderer, std::initializer_list<float> background_color = { 0.1f, 0.1f, 0.1f });
void imgui_cleanup();