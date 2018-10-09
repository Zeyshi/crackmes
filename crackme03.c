#include <stdio.h>
#include <string.h>

// This crackme adds a hardcoded mask to its hardcoded password.

#define CORRECT_LEN 8

// Returns one if the given password is equal to the given correct word masked
// with the given mask.
int check_pw(char* password, char* correct, char* mask) {
    // Look at each character of the submitted string, computing the mask along the way.
    int i = 0;
    // If this is never modified, the password was right.
    char success = 1;
    do {
        char masked_char = correct[i] + mask[i];
        if (masked_char != password[i]) {
            return 0;
        }
        i++;
    } while (correct[i] != 0 && password[i] != 0);
    return 1;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }

    int i;
    int l = 0;
    char correct[CORRECT_LEN + 1] = "password";
    char mask[CORRECT_LEN + 1] = {3, 5, 2, 4, 1, 2, 3, 1};
    char flag[] = { 0x15, 0x0a, 0x14, 0x10, 0x03, 0x1f, 0x45, 0x11, 0x2c, 0x15, 0x1a, 0x28, 0x1e, 0x45, 0x06, 0x11, 0x0e };
    char rly[] = { 0x34, 0x08, 0x17, 0x53, 0x0e, 0x00, 0x07, 0x44, 0x02, 0x04, 0x12, 0x1f, 0x1b, 0x16, 0x52, 0x10, 0x18, 0x08, 0x1d, 0x18, 0x57, 0x06, 0x06, 0x44, 0x07, 0x00, 0x00, 0x53, 0x10, 0x00, 0x1b, 0x0a, 0x17, 0x41, 0x07, 0x1c, 0x57, 0x0d, 0x17, 0x44, 0x04, 0x09, 0x12, 0x07, 0x57, 0x0a, 0x13, 0x17, 0x09, 0x5e };
    char output[51];
    if (!strncmp(argv[1], correct, CORRECT_LEN)){
        for(i=0; i<50; i++){
            if (argv[1][l] == 0){
                l = 0;
            }
            char temp = rly[i] ^ argv[1][l];
            output[i] = temp;
            l++;
        }
        output[i] = '\0';
        printf("%s", output);
        return 0;
    } else {
        if (strlen(argv[1]) == CORRECT_LEN && check_pw(argv[1], correct, mask)) {
            printf("Yes, %s is correct!\n", argv[1]);
            printf("Here is your flag:\n");
            for(i=0; i<17; i++){
                if (argv[1][l] == 0){
                    l = 0;
                }
                char temp = flag[i] ^ argv[1][l];
                output[i] = temp;
                l++;
            }
            output[i] = '\0';
            printf("%s", output);
            return 0;
        }
    }
    
    printf("No, %s is not correct.\n", argv[1]);
    return 1;

}
