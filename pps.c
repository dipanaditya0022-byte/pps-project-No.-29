// Member 1(Aditya Sharma ) -Course Catalog and Data Structures
catalog.h
    #ifndef CATALOG_H
    #define CATALOG_H

    #define MAX_COURSES 50
    #define MAX_CODE 10
    #define MAX_PREREQ 5

typedef struct{ 
    char code[MAX_CODE];
    int creditHours;
    int numPrereq;
    char prereq[MAX_PREREQ][MAX_CODE];
    int semster;  //1=Fall, 2=Spring etc
}Course;    

extern Course catalog[MAX_COURSES];
extern int courseCount;

void loadCatalog();
void displayCatalog();
int findCourseIndex(char code[]);

#endif
    catalog.c
    #include<stdio.h>
    #include<string.h>
    #include "catalog.h"
Course catalog[MAX_COURSES];
int courseCount = 0;
// Member 4(Aditya Srivastav) - Schedule Checker(Time Conflicts + Overload) //
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
