void checkScheduleConflicts(){
  printf("\nChecking schedule conflicts...\n);
  printf("(Demo) No time conflicts detected.\n");
}
void checkOverload(){
  printf("\nChecking credit overload...\n");
int total=0;

for (int i=0;i<planCount;i++){
int idx=findCourseindex(studentPlan[i]);
total+=catalog[idx].creditHours;
}
if(total>18)
  printf("WARNING: You are overloaded (%d credits)!\n",total);
else
  printf("Credit load OK (%d credits)\n",total);
}
