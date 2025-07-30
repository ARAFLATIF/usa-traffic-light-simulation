#include <stdio.h>          // For input/output functions
#include "simulation.h"     // Include the simulation header
#include "config.h"         // Include configurations for constants

// Initialize the traffic lights with default states and durations
void initializeTrafficLights(TrafficLight lights[], int numLights) {
    for (int i = 0; i < numLights; i++) {
        initializeTrafficLight(&lights[i], i + 1); // Use the proper initialization function
    }
}

// Simulate one cycle of a single traffic light
void simulateTrafficLightCycle(TrafficLight *light) {
    // Use the updateTrafficLight function for consistency
    updateTrafficLight(light);
}

// Adjust traffic light durations dynamically based on traffic flow
void adjustTrafficLightDurations(TrafficLight lights[], int numLights, int trafficFlow) {
    for (int i = 0; i < numLights; i++) {
        // Adjust durations for peak traffic conditions
        if (trafficFlow > HIGH_TRAFFIC_THRESHOLD) {
            lights[i].duration = (lights[i].currentState == GREEN) ? PEAK_GREEN_DURATION :
                                 (lights[i].currentState == RED) ? PEAK_RED_DURATION :
                                 PEAK_YELLOW_DURATION;
        }
        // Adjust durations for low traffic conditions
        else if (trafficFlow < LOW_TRAFFIC_THRESHOLD) {
            lights[i].duration = (lights[i].currentState == GREEN) ? LOW_GREEN_DURATION :
                                 (lights[i].currentState == RED) ? LOW_RED_DURATION :
                                 LOW_YELLOW_DURATION;
        }
        // Otherwise, use default durations
        else {
            lights[i].duration = (lights[i].currentState == GREEN) ? DEFAULT_GREEN_DURATION :
                                 (lights[i].currentState == RED) ? DEFAULT_RED_DURATION :
                                 DEFAULT_YELLOW_DURATION;
        }
    }
}

// Handle pedestrian crossing requests
void handlePedestrianRequests(TrafficLight lights[], int numLights) {
    for (int i = 0; i < numLights; i++) {
        if (getRandomNumber(1, 100) <= PEDESTRIAN_REQUEST_PROBABILITY) {
            // Temporarily set the light to RED for pedestrian crossing
            lights[i].currentState = RED;
            lights[i].duration = PEDESTRIAN_CROSSING_DURATION;
            lights[i].timeElapsed = 0;
            lights[i].remainingTime = PEDESTRIAN_CROSSING_DURATION;
            printf("Pedestrian crossing requested at light %d.\n", lights[i].id);
        }
    }
}

// Main simulation loop for running the traffic light system
void runTrafficLightSimulation(TrafficLight lights[], int numLights, int simulationTime) {
    printf("Starting traffic light simulation for %d seconds...\n", simulationTime);

    for (int time = 0; time < simulationTime; time++) {
        printf("\nSimulation Time: %d seconds\n", time + 1);

        // Handle pedestrian requests (random events)
        handlePedestrianRequests(lights, numLights);

        // Update each traffic light in the system
        for (int i = 0; i < numLights; i++) {
            simulateTrafficLightCycle(&lights[i]); // Update the state of the light
            
            // Enhanced visual output for demo
            const char* visualState = "";
            switch (lights[i].currentState) {
                case RED:    visualState = "[🔴 RED]"; break;
                case GREEN:  visualState = "[🟢 GREEN]"; break;
                case YELLOW: visualState = "[🟡 YELLOW]"; break;
            }
            
            printf("Light %d: %s - Time: %d/%d sec\n",
                   lights[i].id, visualState,
                   lights[i].timeElapsed, lights[i].duration);
        }

        // Adjust light durations based on traffic flow
        adjustTrafficLightDurations(lights, numLights, getRandomNumber(5, 50));

        // Delay for one simulation tick (real-time representation)
        delay(SIMULATION_TICK_MS);
    }

    printf("\nTraffic light simulation ended.\n");
}

// Main simulation function called from main.c
void runSimulation(TrafficLight lights[], int numLights, int trafficFlowLevel, int debugMode) {
    int simulationTime = 30; // Shorter demo time - 30 seconds
    
    // Display traffic conditions without storing the value
    switch (trafficFlowLevel) {
        case 1: // Low traffic
            printf("🚗 Running simulation with LOW traffic conditions...\n");
            adjustTrafficLightDurations(lights, numLights, LOW_TRAFFIC_THRESHOLD / 2);
            break;
        case 3: // High traffic
            printf("🚙🚕🚗 Running simulation with HIGH traffic conditions...\n");
            adjustTrafficLightDurations(lights, numLights, HIGH_TRAFFIC_THRESHOLD + 10);
            break;
        default: // Normal traffic
            printf("🚗🚙 Running simulation with NORMAL traffic conditions...\n");
            adjustTrafficLightDurations(lights, numLights, (LOW_TRAFFIC_THRESHOLD + HIGH_TRAFFIC_THRESHOLD) / 2);
            break;
    }
    
    if (debugMode) {
        printf("🔧 Debug mode enabled - showing detailed information\n");
    }
    
    printf("\n🚦 Starting traffic light simulation...\n");
    printf("Press Ctrl+C to stop the simulation early\n\n");
    
    // Run the main simulation
    runTrafficLightSimulation(lights, numLights, simulationTime);
}
