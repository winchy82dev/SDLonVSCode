This is a basic starting file in C programming language, using SDL2
It's only work on windows, and require Mingw32 to be installed

## Requirements
Download and Install [Mingw32](https://www.mingw-w64.org/downloads/)
then install those packages from MinGW Installation Manager
![](./doc/MinGW_packages.jpg)
Download [SDL2](https://github.com/libsdl-org/SDL/releases)
Download [SDL_mage](https://github.com/libsdl-org/SDL_image/releases)

In this project, i'm using the 32 bit version - i686-w64-mingw32

## Configuration
You'll find 4 files on the `.vscode` folder :

1. c_cpp_properties.json
    * Add your current workspace folder
    and the path to the sdl 
    
    ```json
    "includePath": [
        "${workspaceFolder}/**",
        "C:\\tools\\sdl2-32\\include"
      ]
    ```
    * on the `compilerPath` property, specify path to your compiler, 
    i'm using gcc from MinGW

    ```json
    "compilerPath": "C:/MinGW/bin/gcc.exe",
    ```
    
1. launch.json
    * add a new property called `preLaunchTask` and name it whatever you want
    you 'll refer to it on `label` property on the `tasks.json` file

    ```json
    "preLaunchTask": "SDL2"
    ```
    
1. settings.json
    * on this file you have to add the path of the headers of the SDL library to 
    the `C_Cpp_Runner.includePaths` property

    ```json
    "C_Cpp_Runner.includePaths": [
    "${workspaceFolder}/**",
    "C:\\tools\\sdl2-32\\include"
  ],
    ```
1. tasks.json
    * specify the name of this task on `label` property

    ```json
    "label": "SDL2"
    ```
    * then add those arguments, we are linking the `include` and `lib` folder of the SDL2

    ```json
    "args": [
				"-fdiagnostics-color=always",
				"-g",
				"${workspaceFolder}\\*.c",
				"-o",
				"${workspaceFolder}\\build\\Debug\\outDebug.exe",
				"-IC:/tools/sdl2-32/include",
				"-LC:/tools/sdl2-32/lib",
				"-lmingw32",
				"-lSDL2main",
				"-lSDL2",
				"-lSDL2_image",
				"-mwindows",
				""
			]
    ```

