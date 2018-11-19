#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/wait.h> 
#include<unistd.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>


int main(){
  srand(time(0));
  int f1;
  int f2;
  int slp1 = rand()%15+5;
  int slp2 = rand()%15+5;
  
  if((f1 = fork())){
    if((f2 = fork())){
      printf("Parent %d\n", getpid());
      int status;
      int childpid = wait(&status);
      printf("Process %d slept for %d seconds: DONE\n", childpid, WEXITSTATUS(status));
      return 0;
    }
    else{
      printf("Child: %d ", getpid());
      printf("sleeping for %d\n", slp1);
      sleep(slp1);
      printf("Child %d slept for %d seconds\n", getpid(), slp1);
      return slp1;
    }
  }
	
  printf("Child: %d ", getpid());
  printf("sleeping for %d\n", slp2);
  sleep(slp2);
  printf("Child %d slept for %d seconds\n", getpid(), slp2);
  return slp2;
}
