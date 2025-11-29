#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PREREQ 5
#define MAX_COURSES 50
#define MAX_CODE 10

// -----------------------------
// Structures
// -----------------------------
typedef struct {
    char code[MAX_CODE];
    int creditHours;
    char semester[10];
    int timeslot;
    int prereqCount;
    char prereqs[MAX_PREREQ][MAX_CODE];
} Course;

