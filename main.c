#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h> // Include ctype.h for isdigit() function
#include "sub.c"
#include "sub.h"

int main() {
    Transaction* transactionList = NULL; // Initialize the transaction list
    addTransaction(&transactionList, "Cash Withdrawal", cashWithdrawal); // Add "Cash Withdrawal" transaction to the list
    addTransaction(&transactionList, "Cash Deposit", cashDeposit); // Add "Cash Deposit" transaction to the list
    addTransaction(&transactionList, "Fund Transfer", fundTransfer); // Add "Fund Transfer" transaction to the list
    addTransaction(&transactionList, "Account Services", accountServices); // Add "Account Services" transaction to the list
    addTransaction(&transactionList, "Exit", exitATM); // Add "Exit" transaction to the list

    displayTransactions(transactionList); // Display the available transactions
    int attempts = 0; // Initialize the PIN attempts counter
    bool authenticated = false; // Initialize the authentication status
    while (attempts < MAX_ATTEMPTS) {
        char accountNumberInput[100]; // Declare a character array to store the account number input
        printf("Enter your account number: "); // Prompt the user to enter the account number
        scanf("%s", accountNumberInput); // Read the account number input as a string

        // Validate that the input contains only numeric characters
        bool isValidAccountNumber = true;
        for (int i = 0; accountNumberInput[i] != '\0'; i++) {
            if (!isdigit(accountNumberInput[i])) {
                isValidAccountNumber = false;
                break;
            }
        }

        if (isValidAccountNumber) {
            int accountNumber = atoi(accountNumberInput); // Convert the validated input to an integer
            printf("Enter your PIN: "); // Prompt the user to enter the PIN

            // Read the PIN character by character without echoing to the console
            char pin[PIN_LENGTH + 1]; // +1 for null terminator
            for (int i = 0; i < PIN_LENGTH; i++) {
                pin[i] = _getch(); // Read a character
                printf("*"); // Print an asterisk instead of the actual character
            }
            pin[PIN_LENGTH] = '\0'; // Null terminator

            attempts++; // Increment the PIN attempts counter

            if (validatePIN(atoi(pin), accountNumber)) {
                authenticated = true; // Set the authentication status to true
                break; // Exit the loop
            } else {
                printf("\nInvalid account number or PIN. Please try again.\n"); // Display an error message for invalid account number or PIN
            }
        } else {
            printf(" Please enter a valid numeric account number.\n"); // Display an error message for invalid account number
        }
    }

    if (!authenticated) {
        printf("\nMaximum PIN attempts exceeded. Exiting...\n"); // Display an error message for maximum PIN attempts exceeded
        return 0; // Exit the program
    }

    int choice;
    while (1) {
        printf("\nEnter transaction number: "); // Prompt the user to enter the transaction number
        scanf("%d", &choice); // Read the transaction number from the user
        if (choice >= 1 && choice <= 5) {
            Transaction* current = transactionList;
            for (int i = 1; i < choice; i++) {
                current = current->next;
            }
            current->transactionFunc(); // Execute the selected transaction
        } else if (choice == 6) {
            exitATM(); // Execute the "Exit" transaction
        } else {
            printf("\nInvalid choice. Please try again.\n"); // Display an error message for invalid choice
        }
    }

    return 0;
}

