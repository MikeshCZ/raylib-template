<a href="https://www.buymeacoffee.com/michalsara" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-red.png" alt="Buy Me A Coffee" style="height: 60px !important;width: 217px !important;" ></a>

# Raylib Template



## Enjoy your development journey with [Raylib](https://www.raylib.com)! 🎮

A versatile template for **Raylib** projects using **C++** and **CMake**, optimized for **MacOS** and **Windows** with full integration for **Visual Studio Code**.

This template automatically checks for the presence of **Raylib** and **Raygui** libraries during build. If missing, they will be automatically downloaded into the build folder to ensure a smooth setup.

---

# Installation

## For **MacOS**:

1. **Install prerequisites**:
   - **Xcode**: Download from the [App Store](https://apps.apple.com/us/app/xcode/id497799835?mt=12).
   - **Visual Studio Code**: Download from [here](https://code.visualstudio.com/).
   
2. **Open the folder in VS Code**:
   - Use the command: `code .`

### Recommended: **Homebrew Installation (macOS)**

Homebrew is the recommended package manager for managing libraries on macOS.

#### Install Homebrew:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
#### Install Raylib:

```
brew install raylib cmake
```

## For **Windows**:

1. **Install MSYS2**:
   - Download from [here](https://www.msys2.org/).

2. **Set up MSYS2 for C++ development**:
   - Open the **UCRT64** terminal environment and run the following command:
   
     ```bash
     pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-make mingw-w64-ucrt-x86_64-ninja mingw-w64-ucrt-x86_64-gdb mingw-w64-ucrt-x86_64-lldb
     ```

3. **Update the Windows System Environment PATH**:
   - Add the following paths:
   
     ```
     C:\msys64\ucrt64\bin; c:\msys64\usr\bin
     ```

4. **Install Visual Studio Code**:
   - Download from [here](https://code.visualstudio.com/).

5. **Open the folder in VS Code**:
   - Use the command: `code .`

# Using the Template

Once the environment is set up:

1. Open the folder in **Visual Studio Code**.
2. Press **F5** to start debugging the application.
3. Select **Build and Launch** from the menu.
4. The template will generate a `/build` folder with an executable named after the main folder.

## 

## If you like this repository you can **[buy me a coffee](https://www.buymeacoffee.com/michalsara)**. Thank You!
