option(COMPILE_EXAMPLE_002 "Enable compilation of Example 002" OFF)
#NOTE example_002 - Executable
if(COMPILE_EXAMPLE_002)
  aux_source_directory(${PROJECT_SOURCE_DIR}/src/examples/002/ EXAMPLE_002_FILES)                                                     #NOTE AUX find all cpp/h files in source folder
  add_executable(example_002 ${EXAMPLE_002_FILES})                                                                                    #NOTE Create Executable
  #target_include_directories(example_001 PRIVATE ${PROJECT_SOURCE_DIR}/src/Engine ${PROJECT_SOURCE_DIR}/src/Engine/Algorithms)       #NOTE Include all h files in source folders
  target_link_libraries(example_002 PRIVATE project_warnings project_options Amber_SDL)                                             #NOTE Link
endif()
