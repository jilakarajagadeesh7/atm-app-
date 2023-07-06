//This code represents an ATM program implemented in C. It prompts the user to enter their account number and PIN.
//If the PIN is correct, it presents a menu of options for cash deposit, withdrawal, fund transfer, or account services.
//The user's choice is then processed accordingly. The program also includes functionality to hide the password input and limit
//the password length to four characters.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sub.h"

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

#ifdef _WIN32
    int getch() {
        return _getch();
    }
#else
    int getch() {
        struct termios oldattr, newattr;
        int ch;
        tcgetattr(STDIN_FILENO, &oldattr);  // Get the current terminal attributes
        newattr = oldattr;
        newattr.c_lflag &= ~(ICANON | ECHO);  // Disable canonical mode and echoing
        tcsetattr(STDIN_FILENO, TCSANOW, &newattr);  // Apply the new terminal attributes
        ch = getchar();  // Read a single character
        tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);  // Restore the original terminal attributes
        return ch;
    }
#endif

void hideInput(char *password) {
    int i = 0;
    while (1) {
        char ch = getch();  // Read a single character without echoing
        if (ch == '\n' || ch == '\r')
            break;
        if (ch == 127 && i > 0) {  // Handle backspace
            putchar('\b');  // Move the cursor back by one position
            putchar(' ');   // Overwrite the character with a space
            putchar('\b');  // Move the cursor back again
            i--;
        } else if (i < 4 && ch != 127) {  // Limit the password length to 4 characters
            putchar('*');  // Display '*' instead of the entered character
            password[i] = ch;  // Store the entered character in the password array
            i++;
        }
    }
    password[i] = '\0';  // Add null terminator to the password string
    printf("\n");
}

int isNumeric(const char *str) {
    while (*str) {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

int main() {
    int option;
    char password[5];
    int attempts = 0;
    int pinValidated = 0;  // Flag to track if PIN is validated or not

    // Display menu options
    printf("Welcome to the ATM!\n");
    printf("1. Cash Deposit\n");
    printf("2. Cash Withdrawal\n");
    printf("3. Fund Transfer\n");
    printf("4. Account Services\n");
    printf("5. Exit\n");
    
    // Prompt for account number
    char accountNumber[10];
    printf("Enter your account number: ");
    fgets(accountNumber, sizeof(accountNumber), stdin);
    accountNumber[strcspn(accountNumber, "\n")] = '\0';  // Remove trailing newline

    // Validate account number
    if (!isNumeric(accountNumber)) {
        printf("Invalid account number. Please enter a valid numeric account number.\n");
        return 0;
    }

    while (!pinValidated) {
        // Prompt for PIN
        printf("Enter your PIN: ");
        hideInput(password);

        // Validate PIN
        if (strcmp(password, "1234") == 0) {
            pinValidated = 1;
        } else {
            attempts++;
            if (attempts == 3) {
                printf("Attempts exceeded. Exiting...\n");
                return 0;
            }
            printf("Incorrect PIN. Please try again.\n");
        }
    }

    // Prompt for user input
    printf("Enter your option: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid option. Please try again.\n");
        return 0;
    }

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

    return 0;
}
