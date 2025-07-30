#ifdef _WIN32
#include <windows.h>  // For Windows Sleep function
#else
#define _POSIX_C_SOURCE 199309L  // Enable nanosleep function
#include <time.h>   // For nanosleep on Unix systems
#endif

#include <stdio.h>  // For printf (if needed for debugging)
#include <stdlib.h> // For rand() and srand()
#include <time.h>   // For time()
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
#ifdef _WIN32
    Sleep(milliseconds); // Windows Sleep function takes milliseconds
#else
    struct timespec ts; // Structure to define sleep time
    ts.tv_sec = milliseconds / 1000; // Convert milliseconds to seconds
    ts.tv_nsec = (milliseconds % 1000) * 1000000; // Remaining milliseconds to nanoseconds
    nanosleep(&ts, NULL); // Pause the program for the specified time
#endif
}

// Initialize random seed for better randomness
void initializeRandomSeed() {
    srand((unsigned int)time(NULL));
}

// Clear input buffer to handle input errors
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
