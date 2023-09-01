#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int priority;
    int newValue; // Changed variable name from new_nice_value

    // Get the current priority of the process
    priority = getpriority(PRIO_PROCESS, 0);

    if (priority == -1) {
        perror("getpriority");
        return 1;
    }

    printf("Current priority (nice value): %d\n", priority);

    // Ask the user for a new priority value
    printf("Enter a new priority value (between -20 and 19): ");
    scanf("%d", &newValue); // Changed variable name from new_nice_value

    // Check if the new priority value is within a safe range
    if (newValue < -20 || newValue > 19) { // Changed variable name from new_nice_value
        printf("Error: Priority value is not in the safe range (-20 to 19).\n");
        return 1;
    }

    // Modify the priority using the nice command
    if (nice(newValue) == -1) { // Changed variable name from new_nice_value
        perror("nice");
        return 1;
    }

    // Get the updated priority
    priority = getpriority(PRIO_PROCESS, 0);

    if (priority == -1) {
        perror("getpriority");
        return 1;
    }

    printf("Updated priority (nice value): %d\n", priority);

    return 0;
}

