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
void usage(){
  int a,b,c;
  printf("Usage:\n");
  printf("./a.out user\n");
  printf("./a.out horizontal <filename>\n");
  printf("./a.out vertical <filename>\n");
  printf("Determines how many triangles exist\n");
}
int user(){
  int a,b,c;
  printf("Enter 3 nums\n");
  if(scanf("%d %d %d", &a, &b, &c) != 3){
    printf("INvalid inputs\n");
    return;
  }
  if(isTriangle(a,b,c)){
    printf("valid\n");
  }
  else{
    printf("invalid\n");    
  }
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
    if(sscanf(buffer, "%d %d %d", &a, &b, &c) == 3){
      if(isTriangle(a,b,c)) valid++;
    }
  }
  fclose(fd);
  printf("%d Valid Triangles\n", valid);
  return valid;
}

int vertical(char *fileName){
  return 0;
}

int main(int argc, char* argv[]){
  if(argc < 2){
      printf("")
  }
}
