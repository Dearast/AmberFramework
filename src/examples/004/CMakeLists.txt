option(COMPILE_EXAMPLE_004 "Enable compilation of Example 004" OFF)
#NOTE example_004 - Executable
if(COMPILE_EXAMPLE_004)
  aux_source_directory(${PROJECT_SOURCE_DIR}/src/examples/004/ EXAMPLE_004_FILES)                                                     #NOTE AUX find all cpp/h files in source folder
  add_executable(example_004 ${EXAMPLE_004_FILES})                                                                                    #NOTE Create Executable
  #target_include_directories(example_001 PRIVATE ${PROJECT_SOURCE_DIR}/src/Engine ${PROJECT_SOURCE_DIR}/src/Engine/Algorithms)       #NOTE Include all h files in source folders
  target_link_libraries(example_004 PRIVATE project_warnings project_options Amber_SDL)                                             #NOTE Link
endif()
