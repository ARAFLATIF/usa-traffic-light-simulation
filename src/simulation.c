#include <stdio.h>          // For input/output functions
#include "simulation.h"     // Include the simulation header
#include "config.h"         // Include configurations for constants

// Initialize the traffic lights with default states and durations
void initializeTrafficLights(TrafficLight lights[], int numLights) {
    for (int i = 0; i < numLights; i++) {
        lights[i].id = i + 1; // Assign a unique ID to each traffic light
        lights[i].state = RED; // All lights start in the RED state
        lights[i].duration = DEFAULT_RED_DURATION; // Set initial duration
        lights[i].timeElapsed = 0; // Reset elapsed time
    }
}

// Simulate one cycle of a single traffic light
void simulateTrafficLightCycle(TrafficLight *light) {
    // Transition logic based on the current state
    switch (light->state) {
        case RED:
            if (light->timeElapsed >= light->duration) {
                light->state = GREEN; // Move to GREEN state
                light->duration = DEFAULT_GREEN_DURATION; // Set green duration
                light->timeElapsed = 0; // Reset elapsed time
            }
            break;

        case GREEN:
            if (light->timeElapsed >= light->duration) {
                light->state = YELLOW; // Move to YELLOW state
                light->duration = DEFAULT_YELLOW_DURATION; // Set yellow duration
                light->timeElapsed = 0; // Reset elapsed time
            }
            break;

        case YELLOW:
            if (light->timeElapsed >= light->duration) {
                light->state = RED; // Move to RED state
                light->duration = DEFAULT_RED_DURATION; // Set red duration
                light->timeElapsed = 0; // Reset elapsed time
            }
            break;
    }

    // Increment time elapsed for the current state
    light->timeElapsed++;
}

// Adjust traffic light durations dynamically based on traffic flow
void adjustTrafficLightDurations(TrafficLight lights[], int numLights, int trafficFlow) {
    for (int i = 0; i < numLights; i++) {
        // Adjust durations for peak traffic conditions
        if (trafficFlow > HIGH_TRAFFIC_THRESHOLD) {
            lights[i].duration = (lights[i].state == GREEN) ? PEAK_GREEN_DURATION :
                                 (lights[i].state == RED) ? PEAK_RED_DURATION :
                                 PEAK_YELLOW_DURATION;
        }
        // Adjust durations for low traffic conditions
        else if (trafficFlow < LOW_TRAFFIC_THRESHOLD) {
            lights[i].duration = (lights[i].state == GREEN) ? LOW_GREEN_DURATION :
                                 (lights[i].state == RED) ? LOW_RED_DURATION :
                                 LOW_YELLOW_DURATION;
        }
        // Otherwise, use default durations
        else {
            lights[i].duration = (lights[i].state == GREEN) ? DEFAULT_GREEN_DURATION :
                                 (lights[i].state == RED) ? DEFAULT_RED_DURATION :
                                 DEFAULT_YELLOW_DURATION;
        }
    }
}

// Handle pedestrian crossing requests
void handlePedestrianRequests(TrafficLight lights[], int numLights) {
    for (int i = 0; i < numLights; i++) {
        if (getRandomNumber(1, 100) <= PEDESTRIAN_REQUEST_PROBABILITY) {
            // Temporarily set the light to RED for pedestrian crossing
            lights[i].state = RED;
            lights[i].duration = PEDESTRIAN_CROSSING_DURATION;
            lights[i].timeElapsed = 0;
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
            printf("Light %d: State = %s, Time Elapsed = %d/%d seconds\n",
                   lights[i].id,
                   (lights[i].state == RED) ? RED_STATE_NAME :
                   (lights[i].state == GREEN) ? GREEN_STATE_NAME : YELLOW_STATE_NAME,
                   lights[i].timeElapsed,
                   lights[i].duration);
        }

        // Adjust light durations based on traffic flow
        adjustTrafficLightDurations(lights, numLights, getRandomNumber(5, 50));

        // Delay for one simulation tick (real-time representation)
        delay(SIMULATION_TICK_MS);
    }

    printf("\nTraffic light simulation ended.\n");
}
