add_library(
  "helpers"
  "math.c"
  "random.c"
)
target_compile_features(
  "helpers"
  PUBLIC
  c_std_11
)
target_include_directories(
  "helpers"
  PUBLIC
  "${PROJECT_SOURCE_DIR}/inc"
)
target_link_libraries(
  "helpers"
  PUBLIC
  "SDL2-static"
)