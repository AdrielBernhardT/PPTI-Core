#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int n, level, turn = 5, flag = 1;

    printf("Input Level: ");
    scanf("%d", &level);
    if (level == 1) {
        n = rand()%10+1;
    } else if (level == 2) {
        n = rand()%100+1;
    } else {
        n = rand()%1000+1;
    }
    while (turn > 0)
    {
        printf("Your Turn remaining is %d\n\n", turn);
        int guess;
        printf("Input your guess: ");
        scanf("%d", &guess);
        if (guess == n) {
            flag = 0;
            break;
        } else if (guess < n) {
            printf("Your guess is too low\n\n");
        } else {
            printf("Your guess is too high\n\n");
        }
        turn--;
    }
    if (flag == 1) {
        printf("You Lose\n\n");
    } else {
        printf("You Win\n\n");
    }
    printf("The number is %d\n", n);
    return 0;
}