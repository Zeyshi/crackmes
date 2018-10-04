#include <stdio.h>
#include <string.h>

// A less simple crackme which has its own string comparison function and uses
// a hardcoded, unchanging transform over a hardcoded password.

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }

    char pass[] = "eqttgevjqtugdcvvgt{uvcrng";  // The correct password is "correcthorsebatterystaple"
    char flag[] = { 0x05, 0x03, 0x13, 0x15, 0x1e, 0x01, 0x44, 0x0a, 0x0d, 0x0b, 0x2c, 0x11, 0x56, 0x00, 0x16, 0x18, 0x00, 0x01, 0x04 };
    char output[20];
    
    int i = 0;
    while(pass[i] != 0 && argv[1][i] != 0) {
        if (pass[i] - 2 != argv[1][i]) {
            printf("No, %s is not correct.\n", argv[1]);
            return 1;
        }
        i++;
    }

    printf("Yes, %s is correct!\n", argv[1]);
    printf("Here is your flag:\n");
    for(i=0; i<19; i++){
        char temp = flag[i] ^ argv[1][i];
        output[i] = temp;
    }
    output[i] = '\0';
    printf("%s", output);
    return 0;

}