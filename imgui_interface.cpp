#include "imgui_interface.hpp"

#include <initializer_list>

GLFWwindow *window;

bool imgui_init(int width, int height, const char* title)
{
  // Initialize GLFW
  if (!glfwInit())
  {
    return false;
  }

  // Create a window with OpenGL context
  window = glfwCreateWindow(width, height, title, NULL, NULL);
  if (!window)
  {
    glfwTerminate();
    return false;
  }
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // Enable vsync

  // Initialize ImGui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  // Initialize ImGui for GLFW and OpenGL3
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 130");

  return true;
}

bool imgui_loop(std::function<void()> user_renderer, std::initializer_list<float> background_color)
{
  if (background_color.size() != 3)
  {
    return false;
  }

  while (!glfwWindowShouldClose(window))
  {
    // Poll and handle events
    glfwPollEvents();

    // Start ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    user_renderer();

    // Render
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(background_color.begin()[0], background_color.begin()[1], background_color.begin()[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
  }

  return true;
}

void imgui_cleanup()
{
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
  glfwDestroyWindow(window);
  glfwTerminate();
}