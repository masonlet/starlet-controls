#pragma once

#include "starlet-math/vec2.hpp"

#include <array>
#include <vector>

struct GLFWwindow;

namespace Starlet::Input {
  struct MouseButtonEvent {
    const int button;
    const int action;
    const int mods;
  };

  struct ScrollEvent {
    const double xOffset;
    const double yOffset;
  };

  class MouseManager {
  public:
    static constexpr int BUTTON_MAX = 8; // GLFW_MOUSE_BUTTON_LAST + 1

    void resetButtons();

    void updateMousePosition(GLFWwindow* window);
    void setCursorLocked(const bool locked);
    bool isCursorLocked() const { return cursorLocked; }
    Math::Vec2<double> getMouseDelta() const { return mouseDelta; }

    void onButton(const MouseButtonEvent& event);
    bool isButtonDown(const int button) const;
    bool isButtonPressed(const int button) const;
    std::vector<MouseButtonEvent> consumeButtonEvents();

    void onScroll(const ScrollEvent& event);
    std::vector<ScrollEvent> consumeScrollEvents();

  private:
    static bool validButton(const int button) { return button >= 0 && button < BUTTON_MAX; }

    std::vector<MouseButtonEvent> buttonEvents;
    std::array<bool, BUTTON_MAX> buttonDown{ false };
    std::array<bool, BUTTON_MAX> buttonLast{ false };

    std::vector<ScrollEvent> scrollEvents;

    Math::Vec2<double> mouseDelta{ 0.0, 0.0 };
    Math::Vec2<double> scrollDelta{ 0.0, 0.0 };
    Math::Vec2<double> lastMousePos{ 0.0, 0.0 };
    bool firstMouse{ true }, cursorLocked{ true };
  };
}