#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 100
#define MAX_NAME_LENGTH 50

struct Reservation {
    int seat_number;
    char passenger_name[MAX_NAME_LENGTH];
    int is_reserved;
};

struct Reservation reservations[MAX_SEATS];

void initializeReservationSystem() {
    for (int i = 0; i < MAX_SEATS; i++) {
        reservations[i].seat_number = i + 1;
        reservations[i].is_reserved = 0;
        strcpy(reservations[i].passenger_name, "Available");
    }
}

void displayAvailableSeats() {
    printf("Available Seats:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (!reservations[i].is_reserved) {
            printf("Seat %d: %s\n", reservations[i].seat_number, reservations[i].passenger_name);
        }
    }
}

void reserveSeat() {
    int seat_number;
    char name[MAX_NAME_LENGTH];

    printf("Enter the seat number you want to reserve: ");
    scanf("%d", &seat_number);

    if (seat_number < 1 || seat_number > MAX_SEATS) {
        printf("Invalid seat number. Please enter a valid seat number.\n");
        return;
    }

    if (reservations[seat_number - 1].is_reserved) {
        printf("Seat %d is already reserved by %s.\n", seat_number, reservations[seat_number - 1].passenger_name);
    } else {
        printf("Enter passenger name: ");
        fflush(stdin);
        gets(name);
        strcpy(reservations[seat_number - 1].passenger_name, name);
        reservations[seat_number - 1].is_reserved = 1;
        printf("Seat %d reserved for %s.\n", seat_number, name);
    }
}

int main() {
    int choice;

    initializeReservationSystem();

    while(1<2) {
        printf("\nRailway Reservation System\n\n    By Kunal Ghosh\n\n");
        printf("1. Display available seats\n");
        printf("2. Reserve a seat\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAvailableSeats();
                break;
            case 2:
                reserveSeat();
                break;
            case 3:
                printf("Thank you for using the Railway Reservation System.\n");
                exit(1);
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
