#include "imgui_interface.hpp"

int main()
{
  if (!imgui_init(1280, 720, "ImGui Example"))
  {
    return -1;
  }

  // Set up ImGui style
  ImGui::StyleColorsDark();

  // Variables to track window visibility
  bool show_window1 = true;
  bool show_window2 = true;

  imgui_loop([&] { // Menu bar to reopen windows
    if (ImGui::BeginMainMenuBar())
    {
      if (ImGui::BeginMenu("Windows"))
      {
        if (ImGui::MenuItem("Show Window 1", NULL, show_window1))
        {
          show_window1 = !show_window1;
        }
    
        if (ImGui::MenuItem("Show Window 2", NULL, show_window2))
        {
          show_window2 = !show_window2;
        }
    
        ImGui::EndMenu();
      }
    
      ImGui::EndMainMenuBar();
    }

    // Window 1
    if (show_window1) {
      if (ImGui::Begin("Window 1", &show_window1))
      {
        ImGui::Text("This is Window 1");
      }

      ImGui::End();
    }

    // Window 2
    if (show_window2)
    {
      if (ImGui::Begin("Window 2", &show_window2))
      {
        ImGui::Text("This is Window 2");
      }

      ImGui::End();
    }
  });

  imgui_cleanup();

  return 0;
}
