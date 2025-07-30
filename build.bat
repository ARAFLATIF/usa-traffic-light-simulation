@echo off
REM Traffic Light Simulation Build Script for Windows

echo Building Traffic Light Simulation...

REM Create build directory if it doesn't exist
if not exist build mkdir build

REM Compile the main program
gcc -Wall -Wextra -std=c99 -Iinclude -Isrc -o build\traffic_sim.exe src\main.c src\traffic_light.c src\simulation.c src\user_interface.c src\utils.c

if %ERRORLEVEL% EQU 0 (
    echo Build successful! Executable created: build\traffic_sim.exe
    echo.
    echo You can now run the program with: build\traffic_sim.exe
    echo Or run tests with: build_tests.bat
) else (
    echo Build failed! Please check for compilation errors.
)

pause
