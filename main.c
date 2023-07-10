//This code represents a simple ATM program that allows users to perform various banking operations. 
//It prompts the user for their account number and PIN, hides the PIN input with asterisks, validates the PIN, and presents a menu of options. 
//Depending on the chosen option, it calls the respective function for cash deposit, cash withdrawal, fund transfer, or account services.

//06/07/2023:divided the main .c file into several functtion .c files
//07/07/2023:restricted negative values and alphabets while entering the account number and pin
          //:fixed account number as 9 digits and i provide a valiadate pin in the code
          //:while entering the pin number i displayed (*) instead of numbers in the output to provide pin security
//10/07/2023:i add otp verificarion for the pin change if the user forgot his old pin 
          //:and i added otp verification if the amoumt is more than or equal to 10000
          
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "sub.h"

int getch() {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}

int main() {
    int option;
    int accountNumber;
    int validatePIN = 1234;  // Change this to your desired PIN
    int pinNumber = 0;

    // Display menu options
    printf("Welcome to the ATM!\n");
    printf("1. Cash Deposit\n");
    printf("2. Cash Withdrawal\n");
    printf("3. Fund Transfer\n");
    printf("4. Account Services\n");
    printf("5. Exit\n");

    // Prompt for account number
    printf("Enter your account number (9 digits only): ");
    scanf("%9d", &accountNumber);

    // Consume the newline character from the input buffer
    getchar();

    // Check if the account number has 9 digits
    if (accountNumber < 100000000 || accountNumber > 999999999) {
        printf("Invalid account number. Access denied.\n");
        return 0;
    }

    // Prompt for PIN number
    printf("Enter your PIN number: ");

    // Read PIN number character by character and display asterisks
    int ch;
    while ((ch = getch()) != '\n' && ch != EOF) {
        if (ch >= '0' && ch <= '9') {
            putchar('*');
            pinNumber = pinNumber * 10 + (ch - '0');
        }
    }

    printf("\n");

    // Validate the entered PIN
    if (pinNumber == validatePIN) {
        // Prompt for user input
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                cashDeposit();
                break;
            case 2:
                cashWithdrawal();
                break;
            case 3:
                fundTransfer();
                break;
            case 4:
                accountServices();
                break;
            case 5:
                printf("Thank you for using the ATM. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    } else {
        printf("Invalid PIN. Access denied.\n");
    }

    return 0;
}
