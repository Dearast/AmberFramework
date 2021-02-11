<p align="center">
  <img src="https://github.com/Dearast/AmberEngine/blob/master/amber-export.png" alt="Amber logo">
</p>

# Amber Framework
 - Amber Framework is 2D focused software library.

# OS support
Right now Amber Engine is heavily focused on Linux OS.

# Dependencies in Amber Engine
Amber Engine using template [cpp_starter_project](https://github.com/lefticus/cpp_starter_project) from [Jason Turner | lefticus](https://github.com/lefticus) for C/C++ developing project.\
Another core dependencies are [SFML](https://www.sfml-dev.org/index.php) and in future is planned use also another graphical api like SDL2 and OpenGL.\
Other dependecies list are in described [cpp_starter_project](https://github.com/lefticus/cpp_starter_project).

# Licence
 - Font [font8x8](https://github.com/dhepper/font8x8) by [dhepper](https://github.com/dhepper)

# Compilation
Clone git repository:
```
$ git clone https://github.com/Dearast/AmberFramework.git
```
Installation all dependencies on Arch Linux
```
$ sudo pacman -S gcc clang llvm make cmake doxygen graphviz ccache cppcheck sfml2 --needed
$ yay -S conan include-what-you-use --needed
```
SPDLOG Installation from https://github.com/gabime/spdlog
