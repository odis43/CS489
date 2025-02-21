#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 256


void encodeShellString(char *dest, size_t size, char *src){
   size_t j = 0;
   dest[j] = '"';
   j++;
   for (size_t i = 0; src[i] != '\0' && j < size - 2; i++) {
       if(src[i] == '"'){
          if(dest[j] < size - 3){
             dest[j] = '\\';
          } else {
              break;
          }
       }
       dest[j] = src[i];
       j++;
   }
   dest[j] = '"';
   j++;
   dest[j] = '\0';
}

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    char cmd[BUFSIZE] = {0};
    encodeShellString(cmd, BUFSIZE, argv[1]);
    strcat(cmd, argv[1]);
    system(cmd);
}
