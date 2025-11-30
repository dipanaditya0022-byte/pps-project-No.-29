// Member 1(Aditya Sharma ) -Course Catalog and Data Structures
#include <stdio.h>
#include <string.h.

    #define MAX_COURSES 50
    #define MAX_CODE 10
    #define MAX_PREREQ 5

typedef struct{ 
    char code[MAX_CODE];
    int creditHours;
    int numPrereq;
    char prereq[MAX_PREREQ][MAX_CODE];
    int semster;  
}Course;    

Course catalog[MAX_COURSES];
int courseCount=0;

void loadCatalog();
void displayCatalog();
int findCourseIndex(char code[]);

// LOADS INITIAL CATALOG
void loadCatalog(){
    strcpy(catalog[0].code,"CS101");
    catalog[0].creditHours = 3;
    catalog[0].numPrereq = 0;
    catalog[0].semester = 1;

    strcpy(catalog[0].code,"CS102");
    catalog[1].creditHours = 4;
    catalog[1].numPrereq = 1;
    strcpy(catalog[1].prereq[0],"CS101");
    catalog[1].semster = 2;

    strcpy(catalog[2].code,"CS201");
    catalog[2].creditHours = 3;
    catalog[2].numPrereq = 1;
    strcpy(catalog[2].prereq[0],"CS102");
    catalog[2].semester = 1;

    courseCount = 3;
}
intfindCourseIndex(char code[]){
    for(int i = 0; i<courseCount; i++){
        if(strcmp(catalog[i].code,code) == 0)
            return i;
    } 
    return -1;
}
void displayCatalog(){
    printf("\n===== COURSE CATALOG =====\n");
    for(int i = 0; i<courseCount; i++){
        print(%s(%d credits) | Semester: %d | Prereq: ",
            catalog[i].code,
            catalog[i].creditHours,
            catalog[i].semester);

        if(catalog[i].numPrereq == 0){
            print("None");
        } else{
            for(int j = 0; j<catalog[i].numprereq; j++)
                printf("%s",catalog[i].prereq[j]);
        }
        printf("\n");
    }    
}


prerequisites.h
#ifndef PREREQUISITES_H
#define PREREQUISITES_H

int checkPrerequisites(char courseCode[]);
int detectCycle();

#endif

prerequisites.c
#include <stdio.h>
#include <string.h>
#include "catalog.h"
#include "prerequisites.h"


// MEMBER 2(GAURANSH RAI) CONTRIBUTION: DFS cycle detection for prerequisites
int visited[MAX_COURSES], recStack[MAX_COURSES];
int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < catalog[v].numPrereq; i++) {
        int idx = findCourseIndex(catalog[v].prereq[i]);
        if (idx == -1) continue;

        if (!visited[idx] && dfs(idx))
            return 1;
        else if (recStack[idx])
            return 1;
    }

    recStack[v] = 0;
    return 0;
}

int detectCycle() {
    memset(visited, 0, sizeof(visited));
    memset(recStack, 0, sizeof(recStack));

    for (int i = 0; i < courseCount; i++) {
        if (!visited[i] && dfs(i))
            return 1;
    }
    return 0;
}

int checkPrerequisites(char courseCode[]) {
    int idx = findCourseIndex(courseCode);
    if (idx == -1) return -1;

    printf("\nPrerequisites for %s: ", courseCode);
    if (catalog[idx].numPrereq == 0) {
        printf("None\n");
        return 1;
    }

    for (int i = 0; i < catalog[idx].numPrereq; i++) {
        printf("%s ", catalog[idx].prereq[i]);
    }
    printf("\n");

    return1 ;
}

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


// MEMBER 3(KASHISH SINGH)CONTRIBUTION: Maintain student's semester plan
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


// Member 4(Aditya Srivastava) - Schedule Checker(Time Conflicts + Overload) //
void checkScheduleConflicts(){
    printf("\nChecking schedule conflicts...\n");
    printf("(Demo) No time conflicts detected.\n");
}

void checkOverload(){
    printf("\nChecking credit overload...\n");
int total=0;
for (int i=0;i<planCount;i++){
int idx=findCourseindex(studentPlan[i]);
total+=catalog[idx].creditHours;
}

if (total>18)
    printf("WARNING: You are overloaded (%d credits)!\n",total);
else
    pritnf("Credit load OK (%d credits)\n",total);
}


// Member 1(Aditya Sharma) - calls all modules
int main(){
    loadCatalog();

int choice;
while(1){
printf("\n====COURSE PLANNER MENU====\n");
printf("1. View Catalog\n");
printf("2. Add Course to Plan\n");
printf("3. View Student Plan\n");
printf("4. Check Schedule Conflicts\n");
printf("5. Check Overload\n");
printf("2. Detect Cycles in Prerequisites\n");
printf("0. Exit\n");
printf("Choice: ");
scanf("%d", &choice);

switch (choice){
case 1: displayCatalog(); break;
case 2: addCourseToPlan(); break;
case 3: displayPlan(); break;
case 4: checkScheduleConflicts(); break;
case 5: checkOverload(); break;
case 6: if (detectCycle()) printf("CYCLE DETECTED!\n");
else printf("No cycles found.\n");
break;
case 0: return 0;
    default: printf("Invalid choice!\n");
           }
      }
}
