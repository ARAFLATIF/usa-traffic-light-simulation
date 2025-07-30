#ifndef UTILS_H
#define UTILS_H

#include <time.h> // For time-related functions

// Utility function to get the current time in seconds
time_t getCurrentTime();

// Utility function to generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max);

// Utility function to simulate a delay in milliseconds
void delay(int milliseconds);

// Utility function to initialize random seed
void initializeRandomSeed();

// Utility function to clear input buffer
void clearInputBuffer();

#endif // UTILS_H
