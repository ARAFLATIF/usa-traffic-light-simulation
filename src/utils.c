#include <stdio.h>  // For printf (if needed for debugging)
#include <stdlib.h> // For rand() and srand()
#include <time.h>   // For time() and nanosleep()
#include "utils.h"  // Include the utility function prototypes

// Get the current system time in seconds
time_t getCurrentTime() {
    return time(NULL); // Returns the current time as seconds since Unix epoch
}

// Generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min; // Random number in range [min, max]
}

// Pause execution for a specified number of milliseconds
void delay(int milliseconds) {
    struct timespec ts; // Structure to define sleep time
    ts.tv_sec = milliseconds / 1000; // Convert milliseconds to seconds
    ts.tv_nsec = (milliseconds % 1000) * 1000000; // Remaining milliseconds to nanoseconds
    nanosleep(&ts, NULL); // Pause the program for the specified time
}
