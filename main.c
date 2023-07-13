//This code represents a simple ATM program that allows users to perform various banking operations. 
//It prompts the user for their account number and PIN, hides the PIN input with asterisks, validates the PIN, and presents a menu of options. 
//Depending on the chosen option, it calls the respective function for cash deposit, cash withdrawal, fund transfer, or account services.

//06/07/2023:divided the main .c file into several functtion .c files
//07/07/2023:restricted negative values and alphabets while entering the account number and pin
          //:fixed account number as 9 digits and i provide a valiadate pin in the code
          //:while entering the pin number i displayed (*) instead of numbers in the output to provide pin security
//10/07/2023:i add otp verificarion for the pin change if the user forgot his old pin 
          //:and i added otp verification if the amoumt is more than or equal to 10000
          
#include <stdio.h>        // Standard input/output functions
#include <stdlib.h>       // Standard library functions
#include <termios.h>      // Terminal I/O functions
#include <unistd.h>       // POSIX operating system API functions
#include "sub.h"          // User-defined functions

int getch() {
    struct termios oldattr, newattr;     // Structure for storing terminal attributes
    int ch;                             // Variable for storing input character
    
    tcgetattr(STDIN_FILENO, &oldattr);  // Get current terminal attributes
    newattr = oldattr;                  // Copy current attributes to new attributes
    
    // Disable canonical mode and echo in new attributes
    newattr.c_lflag &= ~(ICANON | ECHO);
    
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);   // Set new terminal attributes
    ch = getchar();                                // Read input character
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);    // Restore old terminal attributes
    
    return ch;      // Return the input character
}

int main() {
    int option;               // Variable for storing menu option
    int accountNumber;        // Variable for storing account number
    int validatePIN = 1234;   // Change this to your desired PIN
    int pinNumber = 0;        // Variable for storing entered PIN
    
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
    int ch;  // Variable for storing each input character
    while ((ch = getch()) != '\n' && ch != EOF) {
        if (ch >= '0' && ch <= '9') {
            putchar('*');  // Display asterisk instead of the entered digit
            pinNumber = pinNumber * 10 + (ch - '0');  // Build the PIN number
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
                cashDeposit();      // Call the function for cash deposit
                break;
            case 2:
                cashWithdrawal();   // Call the function for cash withdrawal
                break;
            case 3:
                fundTransfer();     // Call the function for fund transfer
                break;
            case 4:
                accountServices();  // Call the function for account services
                break;
            case 5:
                printf("Thank you for using the ATM. Goodbye!\n");
                exit(0);            // Exit the program with a return value of 0
            default:
                printf("Invalid option. Please try again.\n");
        }
    } else {
        printf("Invalid PIN. Access denied.\n");
    }
    
    return 0;    // Exit the program with a return value of 0
}
