#include <stdio.h>
#include "user_interface.h"
#include "config.h" // Include configuration for default values and thresholds

// Display a welcome message to the user
void displayWelcomeMessage() {
    printf("========================================\n");
    printf("Welcome to the Traffic Light Simulation!\n");
    printf("========================================\n");
    printf("This program simulates traffic lights with dynamic adjustments.\n");
    printf("You can configure traffic flow, enable debug mode, and more.\n\n");
}

// Display the main menu for the simulation
void displaySimulationMenu() {
    printf("\nSimulation Menu:\n");
    printf("1. Run simulation with current settings\n");
    printf("2. Adjust traffic flow levels (Low, Normal, High)\n");
    printf("3. Toggle debug mode\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// Get user input for traffic flow level
int getUserTrafficFlowLevel() {
    int choice;
    printf("\nSelect Traffic Flow Level:\n");
    printf("1. Low Traffic\n");
    printf("2. Normal Traffic\n");
    printf("3. High Traffic\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    // Validate input
    if (choice < 1 || choice > 3) {
        printf("Invalid choice! Defaulting to Normal Traffic.\n");
        return 2; // Default to Normal Traffic
    }
    return choice;
}

// Display the current status of all traffic lights
void displayTrafficLightStatus(const TrafficLight lights[], int numLights) {
    printf("\nTraffic Light Status:\n");
    for (int i = 0; i < numLights; i++) {
        printf("Light %d: %s (Time Remaining: %d seconds)\n", 
               lights[i].id, 
               lights[i].state == RED ? RED_STATE_NAME :
               lights[i].state == GREEN ? GREEN_STATE_NAME : YELLOW_STATE_NAME,
               lights[i].remainingTime);
    }
}

// Ask the user if they want to enable debug mode
int askEnableDebugMode() {
    char choice;
    printf("\nDo you want to enable debug mode? (y/n): ");
    scanf(" %c", &choice);

    // Return 1 for "yes" and 0 for "no"
    if (choice == 'y' || choice == 'Y') {
        return 1;
    } else if (choice == 'n' || choice == 'N') {
        return 0;
    } else {
        printf("Invalid input! Defaulting to debug mode OFF.\n");
        return 0; // Default to debug mode off
    }
}

// Notify the user of a pedestrian crossing request
void notifyPedestrianRequest(int lightId) {
    printf("\nPedestrian Crossing Request at Light %d\n", lightId);
    printf("Pausing traffic to allow pedestrians to cross safely.\n");
}
