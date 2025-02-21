#include <stdio.h>
#include <stdlib.h>
#include <system.h>
#include <string.h>
#include <time.h>

struct Booking{
    char fullName[35];
    char phoneNum[15];

};



int main(){
    int choice;
    do{
        printf("Hotel GrAnsylvania\n");
        printf("1. Booking Hotel\n");
        printf("2. Print Bookings\n");
        printf("3. Delete Booking\n");
        printf("4. Exit\n");
        scanf("%d", &choice); getchar();
        if (choice < 1 || choice > 4){
            printf("Invalid choice\n");
        }

        if(choice == 1){
            bookingHotel();
        }else if (choice == 2){
            printBookings();
        } else if (choice == 3){
            deleteBooking();
        }

    }while (choice != 4)
    return 0;
}