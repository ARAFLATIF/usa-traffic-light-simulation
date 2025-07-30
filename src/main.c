// FILE STRUCTURE : 

// usa-traffic-light-simulation/
// │
// ├── src/
// │   ├── main.c
// │   ├── traffic_light.c
// │   ├── traffic_light.h
// │   ├── simulation.c
// │   ├── simulation.h
// │   ├── user_interface.c
// │   ├── user_interface.h
// │   ├── utils.c
// │   └── utils.h
// │
// ├── include/
// │   └── config.h
// │
// ├── tests/
// │   ├── test_traffic_light.c
// │   └── test_simulation.c
// │
// ├── docs/
// │   ├── README.md
// │   └── USAGE.md
// │
// ├── Makefile
// └── .gitignore





#include <stdio.h>
#include "config.h"
#include "traffic_light.h"
#include "simulation.h"
#include "user_interface.h"
#include "utils.h"

int main() {
    // Initialize random seed for better randomness
    initializeRandomSeed();
    
    // Display the welcome message
    displayWelcomeMessage();

    // Array to hold the traffic lights in the simulation
    TrafficLight trafficLights[NUM_LIGHTS];

    // Initialize the traffic lights
    initializeTrafficLights(trafficLights, NUM_LIGHTS);

    // Default simulation parameters
    int trafficFlowLevel = 2; // 1 = Low, 2 = Normal, 3 = High
    int debugMode = 0;        // Debug mode disabled by default
    int exitSimulation = 0;   // Flag to track if the user wants to exit

    // Main menu loop
    while (!exitSimulation) {
        // Display the main simulation menu
        displaySimulationMenu();

        // Get the user's choice
        int userChoice;
        while (scanf("%d", &userChoice) != 1) {
            printf("Invalid input! Please enter a number: ");
            clearInputBuffer();
        }
        clearInputBuffer(); // Clear any remaining input

        // Handle the user's menu choice
        switch (userChoice) {
            case 1:
                // Run the simulation
                printf("\nStarting the simulation...\n");
                runSimulation(trafficLights, NUM_LIGHTS, trafficFlowLevel, debugMode);
                break;

            case 2:
                // Adjust traffic flow level
                trafficFlowLevel = getUserTrafficFlowLevel();
                if (trafficFlowLevel == 1) {
                    printf("Traffic flow set to LOW.\n");
                } else if (trafficFlowLevel == 2) {
                    printf("Traffic flow set to NORMAL.\n");
                } else {
                    printf("Traffic flow set to HIGH.\n");
                }
                break;

            case 3:
                // Toggle debug mode
                debugMode = askEnableDebugMode();
                if (debugMode) {
                    printf("Debug mode ENABLED.\n");
                } else {
                    printf("Debug mode DISABLED.\n");
                }
                break;

            case 4:
                // Exit the simulation
                printf("\nExiting the simulation. Goodbye!\n");
                exitSimulation = 1;
                break;

            default:
                // Handle invalid input
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}
