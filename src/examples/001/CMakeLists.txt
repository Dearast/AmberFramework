option(COMPILE_EXAMPLE_001 "Enable compilation of Example 001" OFF)
#NOTE example_001 - Executable
if(COMPILE_EXAMPLE_001)
  aux_source_directory(${PROJECT_SOURCE_DIR}/src/examples/001/ EXAMPLE_001_FILES)                                                     #NOTE AUX find all cpp/h files in cource folder
  add_executable(example_001 ${EXAMPLE_001_FILES})                                                                                    #NOTE Create Executable
  #target_include_directories(example_001 PRIVATE ${PROJECT_SOURCE_DIR}/src/Engine ${PROJECT_SOURCE_DIR}/src/Engine/Algorithms)       #NOTE Include all h files in source folders
  if(COMPILE_WITH_SFML)
    target_link_libraries(example_001 PRIVATE project_warnings project_options Amber_SFML)                                            #NOTE Link
  elseif(COMPILE_WITH_SDL)
    target_link_libraries(example_001 PRIVATE project_warnings project_options Amber_SDL)                                             #NOTE Link
  endif()
endif()
