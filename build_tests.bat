@echo off
REM Traffic Light Simulation Test Build Script for Windows

echo Building and running tests...

REM Create build directory if it doesn't exist
if not exist build mkdir build

REM Compile traffic light tests
echo Compiling traffic light tests...
gcc -Wall -Wextra -std=c99 -Iinclude -Isrc -o build\test_traffic_light.exe tests\test_traffic_light.c src\traffic_light.c src\utils.c

if %ERRORLEVEL% EQU 0 (
    echo Running traffic light tests...
    build\test_traffic_light.exe
) else (
    echo Traffic light test compilation failed!
    goto :end
)

echo.

REM Compile simulation tests  
echo Compiling simulation tests...
gcc -Wall -Wextra -std=c99 -Iinclude -Isrc -o build\test_simulation.exe tests\test_simulation.c src\traffic_light.c src\simulation.c src\utils.c

if %ERRORLEVEL% EQU 0 (
    echo Running simulation tests...
    build\test_simulation.exe
) else (
    echo Simulation test compilation failed!
    goto :end
)

echo.
echo All tests completed!

:end
pause
