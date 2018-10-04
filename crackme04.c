#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Never stores the correct password; instead, accepts any password
// whose length is 32 and whose characters, in ASCII, sum to 3542.

#define CORRECT_LEN 32
#define CORRECT_SUM 137

void pflag() {
    int i;
    int l = 0;
    char temp;
    char output[21];
    char flag[] = { 0x17, 0x1e, 0x12, 0x13, 0x0e, 0x10, 0x04, 0x1c, 0x2c, 0x23, 0x44, 0x02, 0x19, 0x2d, 0x1e, 0x40, 0x21, 0x1e, 0x02, 0x0f };
    char key1[] = { 0x41, 0x42, 0x43, 0x44, 0x45, 0x46 };
    char key2[] = { 0x51, 0x52, 0x53, 0x54, 0x55, 0x56 };
    char key3[] = { 0x61, 0x62, 0x63, 0x64, 0x65, 0x66 };
    for (i=0; i < 20; i++) {
        if (l > 5) {
            l = 0;
        }
        temp = flag[i] ^ key3[l];
        output[i] = temp;
        l++;
    }
    l = 0;
    for (i=0; i < 20; i++) {
        if (l > 5) {
            l = 0;
        }
        temp = output[i] ^ key2[l];
        output[i] = temp;
        l++;
    }
    l = 0;
    for (i=0; i < 20; i++) {
        if (l > 5) {
            l = 0;
        }
        temp = output[i] ^ key1[l];
        output[i] = temp;
        l++;
    }
    output[i] = '\0';
    printf("%s", output);
}

int main(int argc, char** argv) {

    char correct = 0;

    if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }

    // Loop over the whole string
    int i = 0;
    int sum = 0;
    int t;
    while (argv[1][i] != 0) {
        t = argv[1][i] - '0';
        sum += t;
        i++;
    }

    correct = (i == CORRECT_LEN) && (sum == CORRECT_SUM);

    if (correct) {
        printf("Yes, %s is correct!\n", argv[1]);
        printf("Here is your flag:\n");
        pflag();
        return 0;
    } else {
        printf("No, %s is not correct.\n", argv[1]);
        return 1;
    }
}