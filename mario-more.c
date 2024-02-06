#include <stdio.h>

void print_row(int spaces, int bricks, int diez);


int main(void) {
    int n;
    do {
        printf("Height: \n");
        scanf("%d", &n);
        
    } while (n < 1 || n > 8);

    for (int i = 0; i < n; i++) {
        print_row(n - i - 1, i + 1, i + 1);
    }


}

void print_row(int spaces, int bricks, int diez) {
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }

    for (int i = 0; i < bricks; i++) {
        printf("#");
    }

    printf("  ");
    for (int i = 0; i < diez; i++){
        printf("#");
    }


    printf("\n");
}


