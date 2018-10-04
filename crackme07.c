#include <stdio.h>
#include <string.h>

void pflag(char* buf) {
    char output[30];
    char flag[] = { 0x12, 0x04, 0x04, 0x15, 0x1e, 0x2f, 0x11, 0x07, 0x1f, 0x58, 0x07, 0x37, 0x0c, 0x01, 0x3a, 0x23, 0x40, 0x00, 0x02, 0x0b, 0x2b, 0x2a, 0x1c, 0x17, 0x3a, 0x26, 0x09, 0x0c, 0x11 };
    int l = 0;
    int i;
    for (i=0; i<29; i++) {
        if (buf[l] == 0) {
            l = 0;
        }
        char temp = flag[i] ^ buf[l];
        output[i] = temp;
        l++;
    }
    output[i] = '\0';
    printf("%s", output);
}

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }

    char pass[] = { 0x74, 0x1c, 0x0d, 0x17, 0x17, 0x01, 0x14, 0x19, 0x05, 0x00 };
    char decoded[10];

    // decode pass
    decoded[0] = pass[0];
    for (int i=1; i<10; i++) {
        char temp = pass[i] ^ decoded[i-1];
        decoded[i] = temp;
    }
    
    if (strncmp(argv[1], decoded, 10) == 0) {
        printf("Yes, %s is correct!\nEntering Endless Loop...\n", argv[1]);
        int endless = 0;
        while (strncmp(argv[1], decoded, 10) == 0) {
            endless++;
            if (endless > 255) {
                endless = 0;
            }
        }
        printf("Here is your flag:\n");
        pflag(argv[1]);
        
    } else {
        printf("No, %s is not correct.\n", argv[1]);
    }
    return 0;

}