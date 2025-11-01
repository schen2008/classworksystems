#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int err(){
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
}
int isTriangle(int a, int b, int c){
  return (a+b>c) && (a+c>b) && (b+c>a);
}
int main(int argc, char* argv[]){
  return 0;
}
int horizontal(char *fileName){
  FILE *fd = fopen(fileName,"r");
  if(fd==NULL){
    err();
    return -1;
  }
  int a,b,c;
  int valid = 0;
  char buffer[64]; // no idea if this is big enough
  while(fgets(buffer, sizeof(buffer), fd) != NULL){
    if(sscanf(fd, "%d %d %d", &a, &b, &c) == 3){
      if(isTriangle(a,b,c)) valid++;
    }
  }
  fclose(fd);
  printf("%d Valid Triangles\n", valid);
  return valid;
}
