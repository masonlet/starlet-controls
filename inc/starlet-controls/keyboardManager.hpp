#pragma once

#include <vector>
#include <array>

struct KeyEvent {
  const int key;
  const int action;
  const int mods;
};

class KeyboardManager {
public:
  static constexpr int KEY_MAX = 349; // GLFW_KEY_LAST + 1

  void resetKeys();

  void onKey(const KeyEvent& event);
  bool isKeyDown(const int key) const;
  bool isKeyPressed(const int key) const;
  std::vector<KeyEvent> consumeKeyEvents();

private:
  static bool validKey(const int key) { return key >= 0 && key < KEY_MAX; }

  std::vector<KeyEvent> keyEvents;
  std::array<bool, KEY_MAX> keyDown{};
  std::array<bool, KEY_MAX> keyLast{};
};