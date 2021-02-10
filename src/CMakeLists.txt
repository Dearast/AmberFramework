option(COMPILE_EXAMPLE_001 "Enable compilation of Example 001" OFF)
option(COMPILE_EXAMPLE_002 "Enable compilation of Example 002" OFF)
option(COMPILE_EXAMPLE_003 "Enable compilation of Example 003" OFF)
option(COMPILE_WITH_SFML "Enable SFML API" ON)
option(COMPILE_WITH_SDL "Enable SDL API" OFF)

if(COMPILE_WITH_SFML)
  add_definitions(-DCOMPILE_WITH_SFML)
endif()

if(COMPILE_WITH_SDL)
  add_definitions(-DCOMPILE_WITH_SDL)
endif()


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

#NOTE example_002 - Executable
if(COMPILE_EXAMPLE_002)
  aux_source_directory(${PROJECT_SOURCE_DIR}/src/examples/002/ EXAMPLE_002_FILES)                                      #NOTE AUX find all cpp/h files in cource folder for Space Invaders
  add_executable(example_002 ${EXAMPLE_002_FILES})                                                                                  #NOTE Create Executable for Space Invaders
  #target_include_directories(example_001 PRIVATE ${PROJECT_SOURCE_DIR}/src/Engine ${PROJECT_SOURCE_DIR}/src/Engine/Algorithms)       #NOTE Include to Space Invaders all h files in source folders
  target_link_libraries(example_002 PRIVATE project_warnings project_options Amber)                                                 #NOTE Link Engine libraries to Space Invaders
endif()

#NOTE example_003 - Executable
if(COMPILE_EXAMPLE_003)
  aux_source_directory(${PROJECT_SOURCE_DIR}/src/examples/003/ EXAMPLE_003_FILES)                                      #NOTE AUX find all cpp/h files in cource folder for Space Invaders
  add_executable(example_003 ${EXAMPLE_003_FILES})                                                                                  #NOTE Create Executable for Space Invaders
  #target_include_directories(example_001 PRIVATE ${PROJECT_SOURCE_DIR}/src/Engine ${PROJECT_SOURCE_DIR}/src/Engine/Algorithms)       #NOTE Include to Space Invaders all h files in source folders
  target_link_libraries(example_003 PRIVATE project_warnings project_options Amber)                                                 #NOTE Link Engine libraries to Space Invaders
endif()
