/* Caleb Catt Homework 1 */

#include <stdio.h> 
#include<sys/types.h>

int main(int argc, const char * argv[])
{
  FILE* input;
  char output[64];
  char* names[64];
  int arrCounter = 0;
  

  input = fopen("names.txt","r");
  while(!feof(input)) {
    fgets(names,64,input);
    strcpy(output,"mkdir Folders/");
    strcat(output, names);
    char* arg[] = {"/bin/sh", "-c", output, NULL};
    int pid = fork();
    if (pid == 0){
      execve("/bin/sh", arg, NULL);
    }
  }
  return 0; 
}