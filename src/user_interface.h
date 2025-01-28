#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "traffic_light.h" // Include TrafficLight for displaying traffic light details

// Function prototype for displaying the welcome message
void displayWelcomeMessage();

// Function prototype for displaying the simulation menu
void displaySimulationMenu();

// Function prototype for getting user input for traffic flow levels
int getUserTrafficFlowLevel();

// Function prototype for displaying the status of all traffic lights
void displayTrafficLightStatus(const TrafficLight lights[], int numLights);

// Function prototype for asking the user if they want to enable debug mode
int askEnableDebugMode();

// Function prototype for notifying the user about pedestrian crossing requests
void notifyPedestrianRequest(int lightId);

#endif // USER_INTERFACE_H
