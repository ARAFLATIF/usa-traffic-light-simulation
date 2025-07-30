#include <stdio.h>
#include <assert.h>
#include "../src/traffic_light.h"
#include "../include/config.h"

// Test initialization of traffic lights
void testInitializeTrafficLights() {
    TrafficLight trafficLights[NUM_LIGHTS];
    initializeTrafficLights(trafficLights, NUM_LIGHTS);

    for (int i = 0; i < NUM_LIGHTS; i++) {
        // Assert that each traffic light starts in the RED state
        assert(trafficLights[i].currentState == RED);

        // Assert that the remaining time matches the default red duration
        assert(trafficLights[i].remainingTime == DEFAULT_RED_DURATION);
    }

    printf("testInitializeTrafficLights passed.\n");
}

// Test state transitions of a traffic light
void testUpdateTrafficLightState() {
    TrafficLight light;
    initializeTrafficLight(&light, 1); // Initialize a single light

    // Simulate a transition from RED to GREEN
    light.currentState = RED;
    light.remainingTime = 0;
    updateTrafficLight(&light);

    assert(light.currentState == GREEN);
    assert(light.remainingTime == DEFAULT_GREEN_DURATION);

    // Simulate a transition from GREEN to YELLOW
    light.currentState = GREEN;
    light.remainingTime = 0;
    updateTrafficLight(&light);

    assert(light.currentState == YELLOW);
    assert(light.remainingTime == DEFAULT_YELLOW_DURATION);

    // Simulate a transition from YELLOW to RED
    light.currentState = YELLOW;
    light.remainingTime = 0;
    updateTrafficLight(&light);

    assert(light.currentState == RED);
    assert(light.remainingTime == DEFAULT_RED_DURATION);

    printf("testUpdateTrafficLightState passed.\n");
}

int main() {
    printf("Running Traffic Light Tests...\n");
    testInitializeTrafficLights();
    testUpdateTrafficLightState();
    printf("All Traffic Light Tests Passed.\n");
    return 0;
}
