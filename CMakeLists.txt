cmake_minimum_required(VERSION 3.23)

set(CONTROL_NAME starlet_controls)
set(CONTROL_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(CONTROL_INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/inc")

if(NOT TARGET ${CONTROL_NAME})
  add_library(${CONTROL_NAME} STATIC)

  file(GLOB_RECURSE CONTROLS_SRC CONFIGURE_DEPENDS ${CONTROL_SRC_DIR}/*.cpp)
  file(GLOB_RECURSE CONTROLS_HEADERS CONFIGURE_DEPENDS ${CONTROL_INC_DIR}/starlet-controls/*.hpp)

  target_sources(${CONTROL_NAME} PRIVATE ${CONTROLS_SRC} ${CONTROLS_HEADERS})

  target_include_directories(${CONTROL_NAME} 
    PUBLIC 
      $<BUILD_INTERFACE:${CONTROL_INC_DIR}>
      $<INSTALL_INTERFACE:include>
  )

  target_link_libraries(${CONTROL_NAME} 
    PUBLIC 
      glfw 
      starlet_scene 
      starlet_math
  )

  # IDE organization
  source_group(TREE ${CONTROL_SRC_DIR} PREFIX "Source Files" FILES ${CONTROLS_SRC})
  source_group(TREE ${CONTROL_INC_DIR} PREFIX "Header Files" FILES ${CONTROLS_HEADERS})
endif()
