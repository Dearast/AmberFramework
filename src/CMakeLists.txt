option(COMPILE_EXAMPLE_001 "Enable compilation of Example 001" OFF)

#NOTE Engine - Shared library
aux_source_directory(${PROJECT_SOURCE_DIR}/src/framework/ FRAMEWORK_FILES)                                                                  #NOTE AUX find all cpp/h files in source folder for Engine
add_library(Amber SHARED ${FRAMEWORK_FILES})                                                                                            #NOTE Create Engine lib file in lib folder
target_include_directories(Amber PUBLIC ${PROJECT_SOURCE_DIR}/src/framework)                #NOTE Include to Engine all h files in source folders
target_link_libraries(Amber PUBLIC project_options project_warnings spdlog sfml-graphics sfml-window sfml-system)                                      #NOTE Link SDL2, spdlog, docopt, ncurses libraries to Engine
target_compile_definitions(Amber PUBLIC -D_SHARED_LIBRARY_)

#NOTE example_001 - Executable
if(COMPILE_EXAMPLE_001)
  aux_source_directory(${PROJECT_SOURCE_DIR}/src/examples/001/ EXAMPLE_001_FILES)                                      #NOTE AUX find all cpp/h files in cource folder for Space Invaders
  add_executable(example_001 ${EXAMPLE_001_FILES})                                                                                  #NOTE Create Executable for Space Invaders
  #target_include_directories(example_001 PRIVATE ${PROJECT_SOURCE_DIR}/src/Engine ${PROJECT_SOURCE_DIR}/src/Engine/Algorithms)       #NOTE Include to Space Invaders all h files in source folders
  target_link_libraries(example_001 PRIVATE project_warnings project_options Amber)                                                 #NOTE Link Engine libraries to Space Invaders
endif()
