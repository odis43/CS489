#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 256

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    if(strpbrk(argv[1], "!@#$%^&*(){}[]()\\|;`") != NULL){
        fprintf(stderr, "Please provide input without invalid characters");
        return -1;
    }

    char cmd[BUFSIZE] = {0};
    //quote the argument to be treated as a string
    snprintf(cmd, BUFSIZE, "wc -c < \"%s\"", argv[1]);
    system(cmd);
}
