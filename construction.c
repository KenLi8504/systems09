#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct student{
  int sleep;
  double gpa;
  char mood[10];
};

struct student * makeStudent(int hours,double grade, char mentalState[]){
  struct student *stu = malloc(sizeof(struct student));
  stu -> sleep = hours;
  stu -> gpa = grade;
  strcpy(stu -> mood,mentalState);
  return stu;
}

int getInfo(struct student *stu){
  printf("This student got %d hours of sleep on average.\n",stu -> sleep);
  printf("This student's gpa is %lf.\n",stu -> gpa);
  printf("This student is feeling %s.\n",stu -> mood);
  return 0;
}

int main(){
  struct student * example = makeStudent(8,95,"Happy");
  getInfo(example);

  printf("Changing data... \n");
  srand(time(NULL));
  int randomizer = rand();
  if (randomizer % 3 == 0){
    randomizer = rand();
    example -> sleep = randomizer % 10;
  }
  else if (randomizer % 3 == 1){
    randomizer = rand();
    example -> gpa = randomizer % 100;
  }
  else{
    randomizer = rand();
    if (randomizer % 4 == 0){
      strcpy(example -> mood,"Angry");
    }
    else if (randomizer % 4 == 1){
      strcpy(example -> mood,"Stressed");
    }
    else if (randomizer % 4 == 2){
      strcpy(example -> mood,"Sad");
    }
    else{
      strcpy(example -> mood,"Meh");
    }
  }

  getInfo(example);
  return 0;
}
