# Traffic Light Simulation

## Overview
This project simulates the behavior of traffic lights at an intersection. It models state transitions (RED, GREEN, YELLOW) and allows users to modify traffic conditions or request pedestrian crossings.

## Features
- Simulates multiple traffic lights with customizable timings.
- Supports different traffic conditions (low, normal, peak).
- Includes pedestrian crossing functionality.
- Easy-to-use interface for user interaction.

## Setup Instructions
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/traffic-light-simulation.git
   cd traffic-light-simulation

Compile the code using GCC or your preferred C compiler:

gcc -o traffic_sim main.c simulation.c traffic_light.c utils.c user_interface.c -I.
Run the program:

./traffic_sim
(Optional) To run the unit tests:

gcc -o test_traffic_light test_traffic_light.c traffic_light.c utils.c -I.
./test_traffic_light

gcc -o test_simulation test_simulation.c simulation.c traffic_light.c utils.c -I.
./test_simulation


