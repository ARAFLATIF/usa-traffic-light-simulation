#ifndef SIMULATION_H
#define SIMULATION_H

#include "traffic_light.h" // For TrafficLight and enums
#include "utils.h"         // For utility functions

// Initialize the traffic light system (set up all lights and default states)
void initializeTrafficLights(TrafficLight lights[], int numLights);

// Simulate one cycle of the traffic light system (e.g., green, yellow, red transitions)
void simulateTrafficLightCycle(TrafficLight *light);

// Simulate the traffic light system for a specified duration
void runTrafficLightSimulation(TrafficLight lights[], int numLights, int simulationTime);

// Adjust light durations dynamically based on traffic conditions
void adjustTrafficLightDurations(TrafficLight lights[], int numLights, int trafficFlow);

// Handle pedestrian crossing requests during the simulation
void handlePedestrianRequests(TrafficLight lights[], int numLights);

// Main simulation function called from main.c
void runSimulation(TrafficLight lights[], int numLights, int trafficFlowLevel, int debugMode);

#endif // SIMULATION_H
