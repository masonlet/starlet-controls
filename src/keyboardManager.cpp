#include "starlet-controls/keyboardManager.hpp"

#include <GLFW/glfw3.h>

static_assert(KeyboardManager::KEY_MAX == GLFW_KEY_LAST + 1, "KEY_MAX must equal GLFW_KEY_LAST + 1");

void KeyboardManager::resetKeys() {
  keyLast.fill(false);
}

void KeyboardManager::onKey(const KeyEvent& event) {
  if (!validKey(event.key)) return;

  if (event.action == GLFW_PRESS) {
    if (!keyDown[event.key]) keyLast[event.key] = true;
    keyDown[event.key] = true;
  }
  else if (event.action == GLFW_RELEASE)
    keyDown[event.key] = false;

  keyEvents.push_back(event);
}
bool KeyboardManager::isKeyDown(const int key) const {
  return validKey(key) && keyDown[key];
}
bool KeyboardManager::isKeyPressed(const int key) const {
  return validKey(key) && keyLast[key];
}
std::vector<KeyEvent> KeyboardManager::consumeKeyEvents() {
  std::vector<KeyEvent> out = keyEvents;
  keyEvents.clear();
  return out;
}