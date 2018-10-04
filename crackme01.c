#include <stdio.h>
#include <string.h>

// Accepts a hard coded, plaintext, password

int main(int argc, char** argv) {
    
    int i;
    char pass[] = "hellomisteranderson";
    char flag[] = { 0x0e, 0x09, 0x0d, 0x0b, 0x14, 0x1a, 0x0c, 0x1f, 0x17, 0x55, 0x1f, 0x04, 0x31, 0x26, 0x04, 0x11, 0x18, 0x12 };
    char output[19];
    
    if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }

    if (strncmp(argv[1], pass, strlen(pass))) {
        printf("No, %s is not correct.\n", argv[1]);
        return 1;
        
    } else {
        printf("Yes, %s is correct!\n", argv[1]);
        printf("Here is your flag:\n");
        for(i=0; i<18; i++){
            char temp = flag[i] ^ argv[1][i];
            output[i] = temp;
        }
        output[i] = '\0';
        printf("%s", output);
        return 0;
    }

}