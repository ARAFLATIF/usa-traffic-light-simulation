#ifndef CONFIG_H
#define CONFIG_H

// Number of traffic lights in the intersection (e.g., 4 for a 4-way intersection)
#define NUM_LIGHTS 4

// Default durations for each light state (in seconds)
#define DEFAULT_RED_DURATION 30      // Default red light duration
#define DEFAULT_GREEN_DURATION 25    // Default green light duration
#define DEFAULT_YELLOW_DURATION 5    // Default yellow light duration

// Durations for peak traffic conditions (in seconds)
#define PEAK_RED_DURATION 45         // Red light duration during peak hours
#define PEAK_GREEN_DURATION 40       // Green light duration during peak hours
#define PEAK_YELLOW_DURATION 5       // Yellow light duration during peak hours

// Durations for low traffic conditions (in seconds)
#define LOW_RED_DURATION 20          // Red light duration during low traffic
#define LOW_GREEN_DURATION 15        // Green light duration during low traffic
#define LOW_YELLOW_DURATION 5        // Yellow light duration during low traffic

// Pedestrian crossing duration (in seconds)
#define PEDESTRIAN_CROSSING_DURATION 15

// Simulation parameters
#define SIMULATION_TICK_MS 1000      // Simulation tick in milliseconds (1 second)
#define MAX_SIMULATION_TIME 3600     // Maximum simulation time in seconds (1 hour)

// Traffic flow thresholds (cars per minute)
#define LOW_TRAFFIC_THRESHOLD 10     // Minimum number of cars for low traffic
#define HIGH_TRAFFIC_THRESHOLD 30    // Minimum number of cars for high traffic

// Probabilities (as percentages, 0-100)
#define PEDESTRIAN_REQUEST_PROBABILITY 20 // 20% chance of pedestrian request per cycle

// Debug mode flag (Set to 1 to enable debug output)
#define DEBUG_MODE 0

// User interface settings
#define MAX_INPUT_LENGTH 50          // Maximum length for user input

// Light state names (for display purposes)
#define RED_STATE_NAME "RED"
#define GREEN_STATE_NAME "GREEN"
#define YELLOW_STATE_NAME "YELLOW"

// Static assertions to validate configurations
#if DEFAULT_RED_DURATION <= 0 || DEFAULT_GREEN_DURATION <= 0 || DEFAULT_YELLOW_DURATION <= 0
#error "Default light durations must be greater than 0"
#endif

#if PEAK_RED_DURATION <= 0 || PEAK_GREEN_DURATION <= 0 || PEAK_YELLOW_DURATION <= 0
#error "Peak light durations must be greater than 0"
#endif

#if LOW_RED_DURATION <= 0 || LOW_GREEN_DURATION <= 0 || LOW_YELLOW_DURATION <= 0
#error "Low traffic light durations must be greater than 0"
#endif

#if PEDESTRIAN_CROSSING_DURATION <= 0
#error "Pedestrian crossing duration must be greater than 0"
#endif

#if PEDESTRIAN_REQUEST_PROBABILITY < 0 || PEDESTRIAN_REQUEST_PROBABILITY > 100
#error "Pedestrian request probability must be between 0 and 100"
#endif

#endif // CONFIG_H
