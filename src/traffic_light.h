#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include "config.h" // Include the configuration file for durations and other constants

// Enum to represent the different states of a traffic light
typedef enum {
    RED,    // Traffic light is red
    GREEN,  // Traffic light is green
    YELLOW  // Traffic light is yellow
} LightState;

// Structure to represent a single traffic light
typedef struct {
    int id;              // Unique identifier for the traffic light
    LightState currentState;    // Current state of the traffic light (RED, GREEN, YELLOW)
    int duration;        // Duration for the current state (in seconds)
    int remainingTime;   // Time left for the current state to change (in seconds)
    int timeElapsed;     // Time elapsed in current state (in seconds)
} TrafficLight;

// Function prototypes for managing traffic lights
void initializeTrafficLight(TrafficLight* light, int id); // Initialize a traffic light
void updateTrafficLight(TrafficLight* light);             // Update the state of a traffic light
const char* getLightStateName(LightState state);          // Get the name of the current state as a string
void printTrafficLightStatus(const TrafficLight* light);  // Debug function to display traffic light status

#endif // TRAFFIC_LIGHT_H
