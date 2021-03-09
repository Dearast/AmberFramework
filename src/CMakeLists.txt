add_definitions(-DCOMPILE_WITH_SDL)

aux_source_directory(${PROJECT_SOURCE_DIR}/src/framework/ FRAMEWORK_FILES)                                                          #NOTE AUX find all cpp/h files in source folder for Engine
aux_source_directory(${PROJECT_SOURCE_DIR}/src/vendor/imgui IMGUI_FILES)                                                          #NOTE AUX find all cpp/h files in source folder for Engine
aux_source_directory(${PROJECT_SOURCE_DIR}/src/vendor/imgui-sdl IMGUI_SDL_FILES)

if(UNIX)
  #NOTE Amber Framework - Static library
  add_library(Amber_SDL STATIC ${FRAMEWORK_FILES} ${IMGUI_FILES} ${IMGUI_SDL_FILES})
elseif(WIN32)
  #NOTE Amber Framework - Shared library
  add_library(Amber_SDL SHARED ${FRAMEWORK_FILES} ${IMGUI_FILES} ${IMGUI_SDL_FILES})                                                                                    #NOTE Create Engine lib file in lib folder
endif()

target_include_directories(Amber_SDL PUBLIC ${PROJECT_SOURCE_DIR}/src/framework)                                                    #NOTE Include to Engine all h files in source folders
if(ENABLE_CONAN_PKG_SDL2)  #NOTE Option for CONAN package manager that enable install SDL2 by CONAN.
  target_link_libraries(Amber_SDL PUBLIC project_options project_warnings CONAN_PKG::spdlog CONAN_PKG::sdl2)                        #NOTE Link SDL2, spdlog to Amber
else()
  target_link_libraries(Amber_SDL PUBLIC project_options project_warnings spdlog SDL2)                                              #NOTE Link SDL2, spdlog to Amber
endif()
target_compile_definitions(Amber_SDL PUBLIC -D_SHARED_LIBRARY_)

#NOTE exampple_001 - Simple example create framework
add_subdirectory(examples/001)

#NOTE example_002 - Simple examples with Layer
add_subdirectory(examples/002)

#NOTE example_003 - Window creation SFML/SDL2
add_subdirectory(examples/003)

#NOTE example_004 - SDL2 example
add_subdirectory(examples/004)

#NOTE asteroid tunnels - SDL2 example
add_subdirectory(examples/asteroid_tunnels)
