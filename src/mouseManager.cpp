#include "starlet-controls/mouseManager.hpp"

#include <GLFW/glfw3.h>

namespace Starlet::Input {
  static_assert(MouseManager::BUTTON_MAX == GLFW_MOUSE_BUTTON_LAST + 1, "BUTTON_MAX must equal GLFW_MOUSE_BUTTON_LAST + 1");

  void MouseManager::resetButtons() {
    buttonLast.fill(false);
  }

  void MouseManager::updateMousePosition(GLFWwindow* window) {
    double xPos, yPos;
    glfwGetCursorPos(window, &xPos, &yPos);

    if (!cursorLocked) {
      mouseDelta = { 0.0, 0.0 };
      lastMousePos = { xPos, yPos };
      firstMouse = true;
      return;
    }

    if (firstMouse) {
      lastMousePos = { xPos, yPos };
      firstMouse = false;
    }

    mouseDelta.x = xPos - lastMousePos.x;
    mouseDelta.y = lastMousePos.y - yPos;
    lastMousePos = { xPos, yPos };
  }

  void MouseManager::onButton(const MouseButtonEvent& event) {
    if (!validButton(event.button)) return;

    if (event.action == GLFW_PRESS) {
      if (!buttonDown[event.button]) buttonLast[event.button] = true;
      buttonDown[event.button] = true;
    }
    else if (event.action == GLFW_RELEASE)
      buttonDown[event.button] = false;

    buttonEvents.push_back(event);
  }
  bool MouseManager::isButtonDown(const int button) const {
    return validButton(button) && buttonDown[button];
  }
  bool MouseManager::isButtonPressed(const int button) const {
    return validButton(button) && buttonLast[button];
  }

  std::vector<MouseButtonEvent> MouseManager::consumeButtonEvents() {
    std::vector<MouseButtonEvent> events = buttonEvents;
    buttonEvents.clear();
    return events;
  }

  void MouseManager::onScroll(const ScrollEvent& event) {
    scrollEvents.push_back(event);
  }
  std::vector<ScrollEvent> MouseManager::consumeScrollEvents() {
    std::vector<ScrollEvent> events = scrollEvents;
    scrollEvents.clear();
    return events;
  }


  void MouseManager::setCursorLocked(const bool locked) {
    cursorLocked = locked;
    firstMouse = true;
  }
}