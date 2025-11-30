planner.h
#ifndef PLANNER_H
#define PLANNER_H

void addCourseToPlan();
void displayPlan();

#endif

planner.c
#include <stdio.h>
#include <string.h"
#include "catalog.h"
#include "prerequisites.h"
#include "planner.h"


// Maintain student's semester plan
char studentPlan[20][10];
int planCount = 0;

void addCourseToPlan() {
    char code[10];
    printf("Enter course code to add: ");
    scanf("%s", code);

    int idx = findCourseIndex(code);
    if (idx == -1) {
        printf("Course not found!\n");
        return;
    }

    checkPrerequisites(code);
    strcpy(studentPlan[planCount++], code);
    printf("Added %s to your plan.\n", code);
}

void displayPlan() {
    printf("\n===== STUDENT PLAN =====\n");
    int credits = 0;

    for (int i = 0; i < planCount; i++) {
        int idx = findCourseIndex(studentPlan[i]);
        printf("%s (%d credits)\n", studentPlan[i], catalog[idx].creditHours);
        credits += catalog[idx].creditHours;
    }

    printf("Total Credits: %d\n", credits);
}
