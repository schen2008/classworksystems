#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
  // execlp("ls","ls","-a", "-l",NULL);
  // execvp(argv[1],&argv[1]);
  execl("/bin/ls","ls","-a","-l",NULL);
  return 0;
}
