#include <stdio.h>


int calculate_quarters (int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main (void) {

    int cents;
    do {
        printf("Cash owed: \n");
        scanf("%d", &cents);
       
    }
    while (cents < 0);


    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);
    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);
    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5);
    int pennies = calculate_pennies(cents);
    cents = cents - pennies;

    int sum = (quarters + dimes + nickels + pennies);
    printf("%i", sum);
    printf("\n");
    }


 //calculate quarters.
int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;

}

    //calculate dimes.
int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10) {
        dimes++;
        cents = cents - 10;
    }
    return dimes;
}

    //calculate nickels.
int calculate_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5) {
        nickels++;
        cents = cents - 5;
    }

    return nickels;
}


    //calculate pennies.

int calculate_pennies(int cents) {
    int pennies = 0;
    while (cents >= 1) {
      pennies++;
      cents = cents - 1;
}
    return pennies;
}