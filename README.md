# 🚦 USA Traffic Light Simulation

## Overview
This project simulates the behavior of traffic lights at an intersection. It models realistic state transitions (RED → GREEN → YELLOW → RED) and allows users to modify traffic conditions, request pedestrian crossings, and analyze traffic flow patterns.

## ✨ Features
- **Realistic Traffic Light Simulation**: Models 4-way intersection with proper timing
- **Dynamic Traffic Adaptation**: Adjusts light timings based on traffic flow (Low/Normal/High)
- **Pedestrian Crossing System**: Random pedestrian requests that modify light cycles
- **Interactive User Interface**: Menu-driven system with input validation
- **Debug Mode**: Detailed output for monitoring and analysis
- **Cross-Platform Support**: Works on Windows and Unix systems
- **Visual Output**: Enhanced display with emojis and status indicators

## 🏗️ Project Structure
```
usa-traffic-light-simulation/
├── src/                    # Source code files
│   ├── main.c             # Entry point and menu system
│   ├── traffic_light.c    # Traffic light state management
│   ├── traffic_light.h    # Traffic light definitions
│   ├── simulation.c       # Main simulation engine
│   ├── simulation.h       # Simulation function prototypes
│   ├── user_interface.c   # User interaction functions
│   ├── user_interface.h   # UI function prototypes
│   ├── utils.c           # Utility functions (timing, random)
│   └── utils.h           # Utility function prototypes
├── include/               # Header files
│   └── config.h          # Configuration constants and settings
├── tests/                # Unit tests
│   ├── test_traffic_light.c
│   └── test_simulation.c
├── build/                # Compiled executables (created during build)
├── Makefile             # Build configuration for Unix systems
├── build.bat            # Windows build script
├── build_tests.bat      # Windows test build script
├── demo.bat             # Automated demo script
└── README.md            # This file
```

## 🚀 Quick Start

### Windows
1. **Build the project:**
   ```cmd
   .\build.bat
   ```

2. **Run the simulation:**
   ```cmd
   build\traffic_sim.exe
   ```

3. **Run tests:**
   ```cmd
   .\build_tests.bat
   ```

### Linux/macOS
1. **Build the project:**
   ```bash
   make
   ```

2. **Run the simulation:**
   ```bash
   ./build/traffic_sim
   ```

3. **Run tests:**
   ```bash
   make test
   ```

## 🎮 How to Use

### Main Menu Options:
1. **Run simulation with current settings** - Start the traffic light simulation
2. **Adjust traffic flow levels** - Choose between Low/Normal/High traffic
3. **Toggle debug mode** - Enable detailed output for analysis
4. **Exit** - Close the application

### Traffic Flow Levels:
- **Low Traffic**: Shorter light cycles, faster transitions
- **Normal Traffic**: Standard timing configuration
- **High Traffic**: Extended green lights for better flow

### Debug Mode:
When enabled, shows detailed information about:
- State transition timing
- Internal calculations
- Traffic flow adjustments
- Pedestrian crossing events

## ⚙️ Configuration

Key settings in `include/config.h`:
- `NUM_LIGHTS`: Number of traffic lights (default: 4)
- `DEFAULT_*_DURATION`: Standard light timings
- `PEAK_*_DURATION`: High traffic timings
- `LOW_*_DURATION`: Low traffic timings
- `PEDESTRIAN_REQUEST_PROBABILITY`: Chance of pedestrian crossings

## 🧪 Technical Details

### State Machine:
Each traffic light follows the cycle: RED → GREEN → YELLOW → RED

### Timing System:
- Base timing units in seconds
- Cross-platform delay implementation
- Real-time simulation with 1-second ticks

### Random Events:
- Pedestrian crossing requests (configurable probability)
- Traffic flow variations
- Emergency scenarios (future enhancement)

## 🎬 Demo Recording Tips

For the best demo experience:
1. Start with normal traffic to show basic functionality
2. Demonstrate traffic flow adjustments (Low → Normal → High)
3. Show debug mode for technical details
4. Let pedestrian crossings occur naturally
5. Highlight the real-time visual updates

**Recommended demo duration:** 5-10 minutes
**Key features to showcase:**
- Menu navigation
- Different traffic scenarios
- Real-time light state changes
- Pedestrian crossing interruptions

## 🔧 Development

### Compilation Requirements:
- GCC compiler (any recent version)
- C99 standard support
- Windows: MinGW or MSYS2
- Linux/macOS: Standard GCC installation

### Adding Features:
1. Emergency vehicle priority
2. Multi-intersection coordination
3. Traffic statistics tracking
4. Configuration file support
5. Network simulation capabilities

## 📊 Future Enhancements

Potential improvements for the project:
- **Graphics Interface**: SDL or ncurses-based visual display
- **Data Logging**: CSV export for traffic analysis
- **AI Traffic Control**: Machine learning-based optimization
- **Network Simulation**: Multiple connected intersections
- **Real-time Data**: Integration with actual traffic sensors

## 🤝 Contributing

To contribute to this project:
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests for new functionality
5. Submit a pull request

## 📝 License

This project is open source and available under the MIT License.

## 🛠️ Troubleshooting

**Common Issues:**
- **Compilation errors**: Ensure GCC is properly installed
- **Input issues**: Use the provided input validation
- **Timing problems**: Check system clock accuracy
- **Display issues**: Ensure terminal supports Unicode characters

**For Windows users:**
- Use PowerShell or Command Prompt
- Ensure MinGW/MSYS2 is in your PATH
- Some emojis may not display correctly in older terminals

---
