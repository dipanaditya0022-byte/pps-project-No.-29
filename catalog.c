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
