#include "starlet-controls/inputManager.hpp"

namespace Starlet::Input {
	void InputManager::reset() {
		keyboard.resetKeys();
		mouse.resetButtons();
	}

	void InputManager::onKey(const KeyEvent& event) {
		keyboard.onKey(event);
	}
	bool InputManager::isKeyDown(const int key) const {
		return keyboard.isKeyDown(key);
	}
	bool InputManager::isKeyPressed(const int key) const {
		return keyboard.isKeyPressed(key);
	}
	std::vector<KeyEvent> InputManager::consumeKeyEvents() {
		return keyboard.consumeKeyEvents();
	}

	void InputManager::setCursorLocked(const bool locked) {
		mouse.setCursorLocked(locked);
	}
	bool InputManager::isCursorLocked() const {
		return mouse.isCursorLocked();
	}
	Math::Vec2<double> InputManager::getMouseDelta() const {
		return mouse.getMouseDelta();
	}
	void InputManager::updateMousePosition(GLFWwindow* window) {
		mouse.updateMousePosition(window);
	}

	void InputManager::onButton(const MouseButtonEvent& event) {
		mouse.onButton(event);
	}
	bool InputManager::isButtonDown(const int button) const {
		return mouse.isButtonDown(button);
	}
	bool InputManager::isButtonPressed(const int button) const {
		return mouse.isButtonPressed(button);
	}
	std::vector<MouseButtonEvent> InputManager::consumeButtonEvents() {
		return mouse.consumeButtonEvents();
	}

	void InputManager::onScroll(const ScrollEvent& event) {
		mouse.onScroll(event);
	}
	std::vector<ScrollEvent> InputManager::consumeScrollEvents() {
		return mouse.consumeScrollEvents();
	}
}