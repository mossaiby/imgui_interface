#include "imgui_interface.hpp"

int main()
{
  if (!imgui_init(800, 600, "Test"))
  {
    return 1;
  }

  bool show = false;
  float value[3] { 0.0f };

  imgui_loop([&]{
    // Create UI
    ImGui::Begin("Hello, ImGui!");
    ImGui::SliderFloat3("Test", value, 0.0f, 1.0f);

    if (ImGui::Button("Show / hide values"))
    {
      show = !show;
    }

    if (show)
    {
      ImGui::Text("(%g, %g, %g)", value[0], value[1], value[2]);
    }

    ImGui::End();

  });

  imgui_cleanup();

  return 0;
}
