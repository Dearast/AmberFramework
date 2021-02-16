if(ENABLE_USE_SFML)
  add_definitions(-DCOMPILE_WITH_SFML)

  #NOTE Amber Framework - Shared library
  aux_source_directory(${PROJECT_SOURCE_DIR}/src/framework/ FRAMEWORK_FILES)                                                          #NOTE AUX find all cpp/h files in source folder for Engine
  add_library(Amber_SFML SHARED ${FRAMEWORK_FILES})                                                                                   #NOTE Create SHARED lib file in lib folder
  target_include_directories(Amber_SFML PUBLIC ${PROJECT_SOURCE_DIR}/src/framework)                                                   #NOTE Include to Amber all h files in source folders
  if(ENABLE_CONAN_PKG_SFML)
    target_link_libraries(Amber_SFML PUBLIC project_options project_warnings CONAN_PKG::spdlog CONAN_PKG::imgui-sfml)                 #NOTE Link SFML, spdlog to Amber
  else()
    target_link_libraries(Amber_SFML PUBLIC project_options project_warnings spdlog sfml-graphics sfml-window sfml-system)            #NOTE Link SFML, spdlog to Amber
  endif()
  target_compile_definitions(Amber_SFML PUBLIC -D_SHARED_LIBRARY_)
endif()

if(ENABLE_USE_SDL2)
  add_definitions(-DCOMPILE_WITH_SDL)

  #NOTE Amber Framework - Shared library
  aux_source_directory(${PROJECT_SOURCE_DIR}/src/framework/ FRAMEWORK_FILES)                                                          #NOTE AUX find all cpp/h files in source folder for Engine
  add_library(Amber_SDL SHARED ${FRAMEWORK_FILES})                                                                                    #NOTE Create Engine lib file in lib folder
  target_include_directories(Amber_SDL PUBLIC ${PROJECT_SOURCE_DIR}/src/framework)                                                    #NOTE Include to Engine all h files in source folders
  if(ENABLE_CONAN_PKG_SDL2)  #NOTE Option for CONAN package manager that enable install SDL2 by CONAN.
    target_link_libraries(Amber_SDL PUBLIC project_options project_warnings CONAN_PKG::spdlog CONAN_PKG::sdl2)                        #NOTE Link SDL2, spdlog to Amber
  else()
    target_link_libraries(Amber_SDL PUBLIC project_options project_warnings spdlog SDL2)                                              #NOTE Link SDL2, spdlog to Amber
  endif()
  target_compile_definitions(Amber_SDL PUBLIC -D_SHARED_LIBRARY_)
endif()

#NOTE exampple_001 - Simple example create framework
add_subdirectory(examples/001)

#NOTE example_002 - Simple examples with Layer
add_subdirectory(examples/002)

#NOTE example_003 - Window creation SFML/SDL2
add_subdirectory(examples/003)
