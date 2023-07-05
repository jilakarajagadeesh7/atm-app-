#include <stdio.h>
#include <stdlib.h>
#include "sub.h"

void accountServices() {
    int option;

    // Display account services menu
    printf("Account Services:\n");
    printf("1. Balance Inquiry\n");
    printf("2. Change PIN\n");
    printf("3. Statement Request\n");

    // Prompt for user input
    printf("Enter your option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            balanceInquiry();
            break;
        case 2:
            changePIN();
            break;
        case 3:
            statementRequest();
            break;
        default:
            printf("Invalid option. Please try again.\n");
    }
}
