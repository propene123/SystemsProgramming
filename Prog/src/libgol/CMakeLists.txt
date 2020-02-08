add_library(gol SHARED gol.c)
target_include_directories(gol INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})