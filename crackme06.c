#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <time.h>

// Checks that the password is correct and that the machine's localtime is between 0200 and 0359 
#define PASSWORD "notapassword"
#define PASSLEN 11

void pflag(char* buf) {
    char output[23];
    char flag[] = { 0x08, 0x03, 0x15, 0x06, 0x0b, 0x32, 0x27, 0x3c, 0x27, 0x30, 0x3a, 0x50, 0x03, 0x02, 0x40, 0x13, 0x2f, 0x35, 0x1a, 0x1e, 0x44, 0x12 };
    int l = 0;
    int i;
    for (i=0; i<22; i++) {
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


void fail() {
    printf("Access denied.\n");
    exit(1);
}

int cur_hour() {
    time_t rawtime;
    time(&rawtime);
    if (errno != 0) {
        printf("ERROR: Could not get time: %s", strerror(errno));
        return(-1);
    }
    struct tm *current_time = localtime(&rawtime);
    if (errno != 0) {
        printf("ERROR: Could not get time: %s", strerror(errno));
        return(-1);
    }
    return current_time->tm_hour;
}

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }

    int hour = cur_hour();
    char* input = argv[1];

    if (strncmp(input, PASSWORD, PASSLEN) != 0) {
        fail();
    
    // Fail if not between 0200 and 0359
    
    } else if (hour < 2 || hour > 3) {
        int i;
        char yes[] = { 0xa6, 0x9a, 0x8c, 0xd3, 0xdf, 0x8b, 0x97, 0x9e, 0x8b, 0xdf, 0x96, 0x8c, 0xdf, 0x8b, 0x97, 0x9a, 0xdf, 0x9c, 0x90, 0x8d, 0x8d, 0x9a, 0x9c, 0x8b, 0xdf, 0x8f, 0x9e, 0x8c, 0x8c, 0x88, 0x90, 0x8d, 0x9b, 0xd1, 0xd1, 0xd1, 0xdf, 0xbd, 0x8a, 0x8b, 0xdf, 0x86, 0x90, 0x8a, 0xdf, 0x9c, 0x9e, 0x91, 0xd8, 0x8b, 0xdf, 0x97, 0x9e, 0x89, 0x9a, 0xdf, 0x8b, 0x97, 0x9a, 0xdf, 0x99, 0x93, 0x9e, 0x98, 0xdf, 0x8d, 0x96, 0x98, 0x97, 0x8b, 0xdf, 0x91, 0x90, 0x88, 0xd1 };
        char output[76];
        for (i=0; i < 75; i++) {
            char temp = yes[i] ^ 0xff;
            output[i] = temp;
        }
        output[i] = '\0';
        printf("%s\n", output);
        fail();
    }

    printf("Access granted!\n");
    pflag(input);
    exit(0);
    
}