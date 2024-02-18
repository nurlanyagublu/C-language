#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(const char *text);
int count_words(const char *text);
int count_sentences(const char *text);

int main(void) {
    char text[1000]; 

    printf("Text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 

    int l = count_letters(text);
    int w = count_words(text);
    int s = count_sentences(text);

    float alpw = (float)l / w;
    float L = alpw * 100;

    float aspw = (float)s / w;
    float S = aspw * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int rounded_result = round(index);
    printf("%i\n", rounded_result);

    if (rounded_result < 1) {
        printf("Before Grade 1\n");
    } else if (rounded_result >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %i\n", rounded_result);
    }

    return 0;
}

int count_letters(const char *text) {
    int letters = 0;
    for (int i = 0, l = strlen(text); i < l; i++) {
        if (isalpha(text[i])) {
            letters++;
        }
    }
    return letters;
}

int count_words(const char *text) {
    int words = 0;
    for (int i = 0, l = strlen(text); i < l; i++) {
        if (isspace(text[i])) {
            words++;
        }
    }
    return words + 1; // Adding 1 to account for the last word
}

int count_sentences(const char *text) {
    int sentences = 0;
    for (int i = 0, l = strlen(text); i < l; i++) {
        if (ispunct(text[i])) {
            if (text[i] == '!' || text[i] == '.' || text[i] == '?' || text[i] == ';' || text[i] == ':') {
                sentences++;
            }
        }
    }
    return sentences;
}
