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

// MEMBER 2 CONTRIBUTION: DFS cycle detection for prerequisites
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

    return 1;
}
