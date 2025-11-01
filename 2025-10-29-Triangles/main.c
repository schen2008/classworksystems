#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
  FILE * input = fopen("data", r);
  int x,y,z;
  if(argc > 1){
    if(strcmp(argv[1], "user") == 0){
      char * buffer = malloc(sizeof(int)*10);
      buffer = fgets(buffer,10,input);
      sscanf(buffer, "%d %d %d", &x, &y, &z);
    }
  }
}
