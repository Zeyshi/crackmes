#include <stdio.h>
#include <string.h>

// The simplest CrackMe possible

int main(int argc, char** argv) {    
    
    char pass[] = "mellon";
    char flag[] = "flag{M1nes_of_Mor1a}";
    
    if (argc == 1) {
        printf("Speak friend, and enter.\n");
        return -1;
    } else if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }

    if (strncmp(argv[1], pass, strlen(pass))) {
        printf("No, %s is not correct.\n", argv[1]);
        return 1;
        
    } else {
        printf("Yes, %s is correct!\n", argv[1]);
        printf("Here is your flag:\n");
        printf("%s", flag);
        return 0;
    }

}