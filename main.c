//The provided code is an ATM simulation program written in C, which allows users to create new accounts or log in to existing accounts and perform various banking operations.
//It includes functions for handling new user registration, existing user login, and account services such as balance inquiry, cash deposit, cash withdrawal, fund transfer, change PIN, and statement request.
//The code utilizes file handling to store user information and transaction records in separate files ("user_info.txt" and "transactions.txt").
//User input is obtained using the scanf function, and the customGetch function is used to read characters from the input without displaying them.
//The code also includes error handling for file operations and input validation for account numbers, PINs, names, and phone numbers to ensure data integrity.    

#include <stdio.h> // Include the standard input/output library
#include <stdlib.h> // Include the standard library
#include <termios.h> // Include the termios library for terminal I/O
#include <unistd.h> // Include the POSIX operating system API
#include <ctype.h> // Include the library for character classification functions
#include <string.h> // Include the library for string manipulation functions
#include "sub.h" // Include the header file "sub.h"

typedef struct { // Define a structure to represent a user
    char name[50];
    char phoneNumber[15];
    int accountNumber;
    int pinNumber;
} User;

int customGetch(); // Function declaration for customGetch()

void handleNewUser(); // Function declaration for handling new user registration
void handleExistingUser(); // Function declaration for handling existing user login
void accountServices(int *balance, const char* userName); // Function declaration for account services

int main() {
    int userType;

    printf("Are you a new user or an existing user?\n"); // Display a prompt to select user type
    printf("1. New User\n");
    printf("2. Existing User\n");
    printf("Enter your choice: ");
    scanf("%d", &userType); // Read the user's choice for user type
    getchar();

    if (userType == 1) {
        handleNewUser(); // Call the function to handle new user registration
    } else if (userType == 2) {
        handleExistingUser(); // Call the function to handle existing user login
    } else {
        printf("Invalid choice. Exiting...\n"); // Display an error message for invalid choice
    }

    return 0; // Exit the program
}

int customGetch() {
    struct termios oldattr, newattr;
    int ch;

    tcgetattr(STDIN_FILENO, &oldattr); // Get the current terminal attributes
    newattr = oldattr;

    newattr.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echoing

    tcsetattr(STDIN_FILENO, TCSANOW, &newattr); // Set the new terminal attributes
    ch = getchar(); // Get a character from the input without echoing it
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); // Restore the original terminal attributes

    return ch; // Return the character
}

void handleNewUser() {
    User newUser; // Create a new user instance

    printf("Welcome to the ATM!\n"); // Display a welcome message

    printf("Enter your name: "); // Prompt the user to enter their name
    fgets(newUser.name, sizeof(newUser.name), stdin); // Read the user's name from input
    newUser.name[strcspn(newUser.name, "\n")] = '\0'; // Remove the trailing newline character

    for (int i = 0; newUser.name[i] != '\0'; i++) {
        if (!isalpha(newUser.name[i])) { // Check if the name contains only alphabets
            printf("Invalid name. Only alphabets are allowed.\n"); // Display an error message for an invalid name
            return; // Return from the function
        }
    }

    printf("Enter your phone number: "); // Prompt the user to enter their phone number
    fgets(newUser.phoneNumber, sizeof(newUser.phoneNumber), stdin); // Read the user's phone number from input
    newUser.phoneNumber[strcspn(newUser.phoneNumber, "\n")] = '\0'; // Remove the trailing newline character

    for (int i = 0; newUser.phoneNumber[i] != '\0'; i++) {
        if (!isdigit(newUser.phoneNumber[i])) { // Check if the phone number contains only digits
            printf("Invalid phone number. Only digits are allowed.\n"); // Display an error message for an invalid phone number
            return; // Return from the function
        }
    }

    FILE *file = fopen("user_info.txt", "r"); // Open the file "user_info.txt" for reading
    if (file != NULL) {
        int enteredAccountNumber;
        printf("Create your 9-digit account number: "); // Prompt the user to create an account number
        scanf("%d", &enteredAccountNumber); // Read the entered account number
        getchar();

        User existingUser;
        while (fscanf(file, "%s", existingUser.name) != EOF) {
            fscanf(file, "%s", existingUser.phoneNumber);
            fscanf(file, "%d", &existingUser.accountNumber);
            fscanf(file, "%d", &existingUser.pinNumber);

            if (existingUser.accountNumber == enteredAccountNumber) {
                printf("Account number already exists. Please choose a different account number.\n"); // Display an error message for an existing account number
                fclose(file); // Close the file
                return; // Return from the function
            }
        }

        fclose(file); // Close the file

        newUser.accountNumber = enteredAccountNumber;

        printf("Create your 4-digit PIN number: "); // Prompt the user to create a PIN number
        char pin[5];
        int index = 0;
        char c;
        while ((c = customGetch()) != '\n' && index < 4) {
            if (isdigit(c)) {
                putchar('*'); // Echo asterisks instead of the actual digits
                pin[index++] = c;
            }
        }
        pin[index] = '\0';
        newUser.pinNumber = atoi(pin); // Convert the PIN number to an integer

        file = fopen("user_info.txt", "a"); // Open the file "user_info.txt" for appending
        if (file != NULL) {
            fprintf(file, "%s\n", newUser.name); // Write the user's name to the file
            fprintf(file, "%s\n", newUser.phoneNumber); // Write the user's phone number to the file
            fprintf(file, "%d\n", newUser.accountNumber); // Write the user's account number to the file
            fprintf(file, "%d\n", newUser.pinNumber); // Write the user's PIN number to the file
            fclose(file); // Close the file
        } else {
            printf("Error opening file.\n"); // Display an error message for file opening failure
            return; // Return from the function
        }

        printf("\nAccount created successfully!\n"); // Display a success message
    } else {
        printf("Error opening file.\n"); // Display an error message for file opening failure
        return; // Return from the function
    }
}

void handleExistingUser() {
    int option;

    printf("Welcome to the ATM!\n"); // Display a welcome message

    FILE *file = fopen("user_info.txt", "r"); // Open the file "user_info.txt" for reading
    if (file != NULL) {
        printf("Enter your account number: "); // Prompt the user to enter their account number
        int enteredAccountNumber;
        scanf("%d", &enteredAccountNumber); // Read the entered account number
        getchar();

        printf("Enter your PIN number: "); // Prompt the user to enter their PIN number
        char enteredPin[5];
        int index = 0;
        char c;
        while ((c = customGetch()) != '\n' && index < 4) {
            if (isdigit(c)) {
                putchar('*'); // Echo asterisks instead of the actual digits
                enteredPin[index++] = c;
            }
        }
        enteredPin[index] = '\0';
        int enteredPIN = atoi(enteredPin); // Convert the entered PIN number to an integer

        int isValidUser = 0;
        User existingUser;

        while (fscanf(file, "%s", existingUser.name) != EOF) {
            fscanf(file, "%s", existingUser.phoneNumber);
            fscanf(file, "%d", &existingUser.accountNumber);
            fscanf(file, "%d", &existingUser.pinNumber);

            if (existingUser.accountNumber == enteredAccountNumber && existingUser.pinNumber == enteredPIN) {
                isValidUser = 1;
                break;
            }
        }

        fclose(file); // Close the file

        if (isValidUser) {
            printf("\nAuthentication successful!\n"); // Display an authentication success message

            int accountBalance = 1000; // Initialize the account balance to 1000

            while (1) {
                accountServices(&accountBalance, existingUser.name); // Call the function to perform account services

                printf("\nReturn to the main menu (Y/N): "); // Prompt the user to return to the main menu
                char choice;
                scanf(" %c", &choice);
                getchar();

                if (choice == 'Y' || choice == 'y') {
                    continue;
                } else {
                    printf("\nThank you for using the ATM. Goodbye!\n"); // Display a goodbye message
                    return; // Return from the function
                }
            }
        } else {
            printf("\nInvalid account number or PIN. Access denied.\n"); // Display an error message for invalid account number or PIN
        }
    } else {
        printf("Error opening file.\n"); // Display an error message for file opening failure
        return; // Return from the function
    }
}

void accountServices(int *balance, const char* userName) {
    printf("\nWelcome, %s!\n", userName); // Display a welcome message with the user's name
    printf("Select an option:\n");
    printf("1. Balance Inquiry\n");
    printf("2. Cash Deposit\n");
    printf("3. Cash Withdrawal\n");
    printf("4. Fund Transfer\n");
    printf("5. Change PIN\n");
    printf("6. Statement Request\n");

    int option;
    printf("Enter your option: ");
    scanf("%d", &option); // Read the user's option
    getchar();

    FILE *transactionsFile = fopen("transactions.txt", "a+"); // Open the file "transactions.txt" for appending and reading
    if (transactionsFile == NULL) {
        printf("Error opening transactions file.\n"); // Display an error message for file opening failure
        return; // Return from the function
    }

    int existingBalance = 0;
    char transaction[100];
    while (fgets(transaction, sizeof(transaction), transactionsFile) != NULL) {
        if (strstr(transaction, userName) != NULL) {
            char *balanceStr = strchr(transaction, ':');
            if (balanceStr != NULL) {
                existingBalance = atoi(balanceStr + 2);
                break;
            }
        }
    }

    switch (option) {
        case 1:
            balanceInquiry(&existingBalance); // Call the function for balance inquiry
            break;
        case 2: {
            cashDeposit(&existingBalance); // Call the function for cash deposit
            fprintf(transactionsFile, "Deposit: Rs%.2f\n", (float)existingBalance / 100); // Include the deposit record with currency format
            break;
        }
        case 3: {
            cashWithdrawal(&existingBalance); // Call the function for cash withdrawal
            fprintf(transactionsFile, "Withdrawal: Rs%.2f\n", (float)existingBalance / 100); // Include the withdrawal record with currency format
            break;
        }
        case 4: {
            fundTransfer(&existingBalance); // Call the function for fund transfer
            fprintf(transactionsFile, "Transfer: Rs%.2f\n", (float)existingBalance / 100); // Include the fund transfer record with currency format
            break;
        }
        case 5:
            changePIN(); // Call the function to change the PIN number
            break;
        case 6:
            statementRequest(userName); // Call the function for statement request
            break;
        default:
            printf("Invalid option.\n"); // Display an error message for an invalid option
    }

    rewind(transactionsFile); // Move the file position indicator to the beginning of the file
    FILE *tempFile = fopen("temp.txt", "w"); // Open a temporary file for writing

    if (tempFile != NULL) {
        while (fgets(transaction, sizeof(transaction), transactionsFile) != NULL) {
            if (strstr(transaction, userName) == NULL) {
                fputs(transaction, tempFile); // Write the transaction to the temporary file
            }
        }

        fprintf(tempFile, "%s: %d\n", userName, existingBalance); // Write the updated balance to the temporary file
        fclose(tempFile); // Close the temporary file
        fclose(transactionsFile); // Close the transactions file

        remove("transactions.txt"); // Remove the existing transactions file
        rename("temp.txt", "transactions.txt"); // Rename the temporary file to "transactions.txt"
    } else {
        printf("Error updating transactions file.\n"); // Display an error message for file updating failure
        fclose(transactionsFile); // Close the transactions file
        return; // Return from the function
    }
}
