# Starlet Controls
A lightweight input management library for Starlet projects with OpenGL engines in mind.

## Features
- Unified **InputManager** that handles keyboard and mouse inputs
- **KeyboardManager** for key states + key events
- **MouseManager** for cursor movement, scroll, and lock state

## Using as a Dependency
```cmake
include(FetchContent)

FetchContent_Declare(starlet_controls
  GIT_REPOSITORY https://github.com/Masonlet/starlet-controls.git 
  GIT_TAG main
)
FetchContent_MakeAvailable(starlet_controls)

target_link_libraries(app_name PRIVATE starlet_controls)
```
