#include <stdio.h>
#include "user_interface.h"
#include "config.h" // Include configuration for default values and thresholds
#include "utils.h"  // Include utility functions

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
    
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        printf("Invalid choice! Please enter a number between 1 and 3: ");
        clearInputBuffer();
    }
    clearInputBuffer(); // Clear any remaining input
    
    return choice;
}

// Display the current status of all traffic lights
void displayTrafficLightStatus(const TrafficLight lights[], int numLights) {
    printf("\n=== Traffic Light Status ===\n");
    for (int i = 0; i < numLights; i++) {
        const char* stateColor = "";
        const char* stateName = "";
        
        // Add visual indicators for better demo
        switch (lights[i].currentState) {
            case RED:
                stateColor = "[RED]";
                stateName = RED_STATE_NAME;
                break;
            case GREEN:
                stateColor = "[GREEN]";
                stateName = GREEN_STATE_NAME;
                break;
            case YELLOW:
                stateColor = "[YELLOW]";
                stateName = YELLOW_STATE_NAME;
                break;
        }
        
        printf("Light %d: %s %s (Time Remaining: %d seconds)\n", 
               lights[i].id, stateColor, stateName, lights[i].remainingTime);
    }
    printf("=============================\n");
}

// Ask the user if they want to enable debug mode
int askEnableDebugMode() {
    char choice;
    printf("\nDo you want to enable debug mode? (y/n): ");
    
    while (scanf(" %c", &choice) != 1 || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
        printf("Invalid input! Please enter 'y' for yes or 'n' for no: ");
        clearInputBuffer();
    }
    clearInputBuffer(); // Clear any remaining input

    // Return 1 for "yes" and 0 for "no"
    return (choice == 'y' || choice == 'Y') ? 1 : 0;
}

// Notify the user of a pedestrian crossing request
void notifyPedestrianRequest(int lightId) {
    printf("\nPedestrian Crossing Request at Light %d\n", lightId);
    printf("Pausing traffic to allow pedestrians to cross safely.\n");
}
