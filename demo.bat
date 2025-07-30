@echo off
REM Automated Demo Script for Traffic Light Simulation

echo ===================================================
echo        Traffic Light Simulation - DEMO
echo ===================================================
echo.
echo This demo will showcase the traffic light simulation features:
echo 1. Normal traffic conditions
echo 2. High traffic conditions  
echo 3. Low traffic conditions
echo 4. Debug mode demonstration
echo.
pause

echo.
echo === Building the project ===
gcc -Wall -Wextra -std=c99 -Iinclude -Isrc -o build\traffic_sim.exe src\main.c src\traffic_light.c src\simulation.c src\user_interface.c src\utils.c

if %ERRORLEVEL% NEQ 0 (
    echo Build failed! Please check for compilation errors.
    pause
    exit /b 1
)

echo Build successful!
echo.

echo === Running Demo Scenarios ===
echo.

echo Scenario 1: Normal Traffic Simulation
echo Input sequence: 1 (run simulation) -> 4 (exit)
echo 1
echo 4
echo.

echo Scenario 2: High Traffic Simulation  
echo Input sequence: 2 (adjust traffic) -> 3 (high) -> 1 (run) -> 4 (exit)
echo 2
echo 3
echo 1
echo 4
echo.

echo Scenario 3: Debug Mode Simulation
echo Input sequence: 3 (debug mode) -> y (enable) -> 1 (run) -> 4 (exit)
echo 3
echo y
echo 1  
echo 4
echo.

echo Demo complete! You can now run the interactive version with:
echo build\traffic_sim.exe
echo.
pause
