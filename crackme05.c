#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// Reads characters from a given file 

void pflag(char* buf) {
    char output[20];
    char flag[] = { 0x15, 0x19, 0x05, 0x08, 0x5b, 0x07, 0x0f, 0x13, 0x5f, 0x2d, 0x0a, 0x13, 0x1c, 0x07, 0x2a, 0x0c, 0x5b, 0x58, 0x0f };
    int l = 0;
    int i;
    for (i=0; i<19; i++) {
        if (buf[l] == 0) {
            l = 0;
        }
        char temp = flag[i] ^ buf[l];
        output[i] = temp;
        l++;
    }
    output[i] = '\0';
    printf("Here is your flag:\n");
    printf("%s", output);
}


int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }
    
    if (argc == 3) {
        printf("I can haz cheeseburger?");
        printf("What is this? A school for ants?");
        printf("Haikus are easy.\nBut sometimes they don't make sense.\nRefrigerator.\n");
        return -1;
    }

    char* filename = argv[1];
    FILE* f = fopen(filename, "r");
    if (errno != 0) {
        perror("PANIC! Aborting due to");
        return -1;
    }

    char buffer[16];
    int read = fread(buffer, 13, 1, f);
    if (errno != 0) {
        perror("PANIC! Aborting due to");
        return -1;
    }

    if (strncmp("sudo rm -rf /", buffer, 13) != 0) {
        printf("Access denied.\n");
        return -1;
    }
    printf("Access granted!\n");
    pflag(buffer);
    return 0;
}