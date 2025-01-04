# Raylib Template

Starting template for `Raylib` with `C++` and `CMake` for `Visual Studio Code`. Including configuration files for Visual Studio Code. Optimize for MacOS and Windows.

## For MacOS:

1. Install Xcode and Visual Studio Code.

2. Open folder in VS Code. You can use command `code .`.

### Recommended steps for MacOS:

#### Homebrew Installation (macOS)

Homebrew installation is the recommended way to manage your libraries, including raylib, wxWidgets, etc.

##### Install Homebrew:

```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

##### Install Raylib:

```
brew install raylib cmake
```

## For Windows:

1. Install https://www.msys2.org/

2. When MSYS2 is ready for you run terminal for the UCRT64 environment and run install command: `pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-make mingw-w64-ucrt-x86_64-ninja mingw-w64-ucrt-x86_64-gdb mingw-w64-ucrt-x86_64-lldb`

3. Set up Windows System Environment PATH and add: `C:\msys64\ucrt64\bin; c:\msys64\usr\bin`

4. Install Visual Studio Code.

5. Open folder in VS Code. You can use command `code .`.

## Using the Template
If you open the folder in VSCode, you can press `F5` to debug the application immediately. Select `Build and Launch` from the menu. This will generate a `/build` folder and an application named based on main folder name within it.

# Enjoy!
