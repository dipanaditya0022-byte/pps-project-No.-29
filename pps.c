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

// Member 4 - Schedule Checker(Time Conflicts + Overload) //
#indef SCHEDULE_H
#define SCHEDULE_H

void checkScheduleConflicts();
void checkOverload();

#endif

#include <stdio.h>
#include "catalog.h"
#include "planner.h"

void checkScheduleConflicts(){
    printf("\nChecking schedule conflicts...\n");
    printf("(Demo) No time conflicts detected.\n");
}

void checkOverload(){
    printf("\nChecking credit overload...\n");
int total=0;
for(int i=0;i<planCount;i++){
int idx=findCourseindex(studentPlan[i]);
total+=catalog[idx].creditHours;
}

if (total>18)
    printf("WARNING: You are overloaded (%d credits)!\n",total);
else
    pritnf("Credit load OK (%d credits)\n",total);
}
