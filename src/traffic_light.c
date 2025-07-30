#include <stdio.h>   // For printf (if debugging or displaying info)
#include "traffic_light.h" // Include the header file for TrafficLight structure and related enums

// Initialize a traffic light with default values
void initializeTrafficLight(TrafficLight* light, int id) {
    light->id = id;                 // Assign a unique ID to the traffic light
    light->currentState = RED;             // Set the initial state to RED
    light->duration = DEFAULT_RED_DURATION; // Use the default RED duration from config.h
    light->remainingTime = light->duration; // Set the remaining time to the initial state's duration
    light->timeElapsed = 0;         // Initialize elapsed time
}

// Update the state of the traffic light based on its remaining time
void updateTrafficLight(TrafficLight* light) {
    // Decrease the remaining time for the current state
    light->remainingTime--;
    light->timeElapsed++;

    // If the remaining time reaches 0, switch to the next state
    if (light->remainingTime <= 0) {
        switch (light->currentState) {
            case RED: // If the current state is RED, switch to GREEN
                light->currentState = GREEN;
                light->duration = DEFAULT_GREEN_DURATION; // Set the duration for GREEN
                break;

            case GREEN: // If the current state is GREEN, switch to YELLOW
                light->currentState = YELLOW;
                light->duration = DEFAULT_YELLOW_DURATION; // Set the duration for YELLOW
                break;

            case YELLOW: // If the current state is YELLOW, switch to RED
                light->currentState = RED;
                light->duration = DEFAULT_RED_DURATION; // Set the duration for RED
                break;
        }

        // Reset the remaining time and elapsed time for the new state
        light->remainingTime = light->duration;
        light->timeElapsed = 0;
    }
}

// Get the name of the current state as a string (for display purposes)
const char* getLightStateName(LightState state) {
    switch (state) {
        case RED:
            return RED_STATE_NAME; // Defined as "RED" in config.h
        case GREEN:
            return GREEN_STATE_NAME; // Defined as "GREEN" in config.h
        case YELLOW:
            return YELLOW_STATE_NAME; // Defined as "YELLOW" in config.h
        default:
            return "UNKNOWN"; // Fallback for invalid states
    }
}

// Debug function to display the traffic light's current status (optional)
void printTrafficLightStatus(const TrafficLight* light) {
    printf("Traffic Light %d: State = %s, Remaining Time = %d seconds\n", 
           light->id, getLightStateName(light->currentState), light->remainingTime);
}
