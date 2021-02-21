option(COMPILE_ASTEROID_TUNNELS "Enable compilation of Asteroids tunnels" OFF)
#NOTE example_004 - Executable
if(COMPILE_ASTEROID_TUNNELS)
  aux_source_directory(${PROJECT_SOURCE_DIR}/src/examples/asteroid_tunnels/ AT_FILES)                                                     #NOTE AUX find all cpp/h files in source folder
  add_executable(at ${AT_FILES})                                                                                    #NOTE Create Executable
  #target_include_directories(example_001 PRIVATE ${PROJECT_SOURCE_DIR}/src/Engine ${PROJECT_SOURCE_DIR}/src/Engine/Algorithms)       #NOTE Include all h files in source folders
  target_link_libraries(at PRIVATE project_warnings project_options Amber_SDL)                                             #NOTE Link
endif()
