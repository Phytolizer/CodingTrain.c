cmake_minimum_required(VERSION 3.12...3.22)

project(
  "CodingTrain.c"
  LANGUAGES "C"
  VERSION "0.1.0"
  DESCRIPTION "The Coding Train challenges in C"
  HOMEPAGE_URL "https://github.com/Phytolizer/CodingTrain.c"
)

include(FetchContent)

FetchContent_Declare(
  "SDL"
  GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
  GIT_TAG "release-2.0.16"
)
option(SDL_SHARED OFF)
FetchContent_MakeAvailable("SDL")

macro(
  CodingTrain_Declare_Challenge
  NAME
)
  add_executable(
    ${NAME}
    WIN32
    ${ARGN}
  )
  target_compile_features(
    ${NAME}
    PRIVATE
    c_std_11
  )
  target_include_directories(
    ${NAME}
    PRIVATE
    "${PROJECT_SOURCE_DIR}/inc"
  )
  target_link_libraries(
    ${NAME}
    "SDL2-static"
  )
  if(WIN32)
    target_link_libraries(
      ${NAME}
      "SDL2main"
    )
  endif()
endmacro()

add_subdirectory("src")