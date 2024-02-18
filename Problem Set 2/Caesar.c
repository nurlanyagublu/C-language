#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

int only_digits(const char *s);
char rotate(char c, int n);

int main(int argc, char *argv[]) {
    if (argc != 2 || !only_digits(argv[1])) {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    int key = atoi(argv[1]);
    char plaintext[1000]; 

    printf("Plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

    printf("Ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++) {
        if (isalpha(plaintext[i])) {
            printf("%c", rotate(plaintext[i], key));
        } else {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}

int only_digits(const char *s) {
    if (strlen(s) == 0) {
        return 0;
    }

    for (int i = 0, n = strlen(s); i < n; i++) {
        if (!isdigit(s[i])) {
            return 0;
        }
    }
    return 1;
}

char rotate(char c, int n) {
    if (isupper(c)) {
        return (c - 'A' + n) % 26 + 'A';
    } else if (islower(c)) {
        return (c - 'a' + n) % 26 + 'a';
    } else {
        return c;
    }
}
