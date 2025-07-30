@echo off
REM Quick test script to verify the program works

echo ===================================
echo   Traffic Light Simulation Test
echo ===================================
echo.

REM Build the project
echo Building project...
gcc -Wall -Wextra -std=c99 -Iinclude -Isrc -o build\traffic_sim.exe src\main.c src\traffic_light.c src\simulation.c src\user_interface.c src\utils.c

if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Build failed!
    pause
    exit /b 1
)

echo ✓ Build successful!
echo.

REM Test compilation of tests
echo Building tests...
gcc -Wall -Wextra -std=c99 -Iinclude -Isrc -o build\test_traffic_light.exe tests\test_traffic_light.c src\traffic_light.c src\utils.c

if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Test build failed!
    pause
    exit /b 1
)

echo ✓ Test build successful!
echo.

REM Run tests
echo Running unit tests...
build\test_traffic_light.exe

if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Tests failed!
    pause
    exit /b 1
)

echo ✓ All tests passed!
echo.

echo ===================================
echo    ✓ Project is ready for demo!
echo ===================================
echo.
echo To run the interactive simulation:
echo   build\traffic_sim.exe
echo.
echo To record a demo:
echo 1. Start screen recording software
echo 2. Run: build\traffic_sim.exe
echo 3. Navigate through menu options:
echo    - Try option 1 (run simulation)
echo    - Try option 2 (adjust traffic flow)
echo    - Try option 3 (debug mode)
echo    - Use option 4 to exit
echo.
pause
