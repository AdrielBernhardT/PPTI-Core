#include <stdio.h>

void printWorkdayCalendar(int countDayInMonth, int startDay) {
    const char *days[] = {"Mo", "Tu", "We", "Th", "Fr"};
    int day = 1;
    
    // Print the header
    for (int i = 0; i < 4; i++) {
        printf("%s|", days[i]);
    }
    printf("%s", days[4]);
    printf("\n");
    printf("--+--+--+--+--", days[4]);
    // Adjust the start day to 0-based index for easier calculation
    startDay = (startDay - 1) % 7;

    // Print leading spaces for the first week
    for (int i = 0; i < startDay; i++) {
        if (i < 5) {
            printf("   ");
        }
    }

    // Print the days
    for (int i = startDay; day <= countDayInMonth; i++) {
        if (i % 7 < 5) { // Only print Monday to Friday
            printf("%2d|", day);
            day++;
        }
        if (i % 7 == 4) { // End of the work week
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int countDayInMonth, startDay;
    printf("Enter the number of days in the month: ");
    scanf("%d", &countDayInMonth);
    printf("Enter the starting day of the month (1 for Monday, ..., 7 for Sunday): ");
    scanf("%d", &startDay);

    printWorkdayCalendar(countDayInMonth, startDay);

    return 0;
}