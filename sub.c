#include <stdio.h>
#include <stdlib.h>
#include "sub.h"
void cashWithdrawal() {
    printf("Performing cash withdrawal...\n"); // Displaying the transaction type
    int amount;
    printf("Select withdrawal amount:\n"); // Prompting the user to select the withdrawal amount
    printf("1. Rs 100\n");
    printf("2. Rs 200\n");
    printf("3. Rs 500\n");
    printf("4. Rs 2000\n");
    printf("Enter your choice: ");
    scanf("%d", &amount); // Reading the user's choice

    switch (amount) {
        case 1:
            printf("Withdrawing Rs 100...\n"); // Performing the withdrawal for Rs 100
            break;
        case 2:
            printf("Withdrawing Rs 200...\n"); // Performing the withdrawal for Rs 200
            break;
        case 3:
            printf("Withdrawing Rs 500...\n"); // Performing the withdrawal for Rs 500
            break;
        case 4:
            printf("Withdrawing Rs 2000...\n"); // Performing the withdrawal for Rs 2000
            break;
        default:
            printf("Invalid choice. No withdrawal made.\n"); // Displaying an error message for an invalid choice
            break;
    }
}

void cashDeposit() {
    printf("Performing cash deposit...\n"); // Displaying the transaction type
    int amount;
    printf("Enter the deposit amount (in Rs): "); // Prompting the user to enter the deposit amount
    scanf("%d", &amount); // Reading the deposit amount

    if (amount > 0 && amount <= MAX_DEPOSIT_AMOUNT) {
        printf("Depositing Rs %d...\n", amount); // Performing the deposit
    } else {
        printf("Invalid deposit amount. Please enter a value between 1 and %d (in Rs).\n", MAX_DEPOSIT_AMOUNT); // Displaying an error message for an invalid deposit amount
    }
}

void fundTransfer() {
    printf("Performing fund transfer...\n"); // Displaying the transaction type
}

void accountServices() {
    printf("Performing account services...\n"); // Displaying the transaction type
    int option;
    printf("Select an option:\n"); // Prompting the user to select an account service option
    printf("1. Balance Inquiry\n");
    printf("2. Mini Statement\n");
    printf("3. PIN Change\n");
    printf("Enter your choice: ");
    scanf("%d", &option); // Reading the user's choice

    switch (option) {
        case 1:
            printf("Performing balance inquiry...\n"); // Performing the balance inquiry
            break;
        case 2:
            printf("Performing mini statement...\n"); // Performing the mini statement
            break;
        case 3:
            printf("Performing PIN change...\n"); // Performing the PIN change
            break;
        default:
            printf("Invalid option.\n"); // Displaying an error message for an invalid option
            break;
    }
}

void exitATM() {
    printf("Exiting ATM...\n"); // Displaying the transaction type
    exit(0); // Exiting the program
}
Transaction* createTransaction(char* name, void (*transactionFunc)()) {
    Transaction* newTransaction = (Transaction*)malloc(sizeof(Transaction)); // Allocate memory for a new Transaction node
    newTransaction->name = name; // Set the name of the transaction
    newTransaction->transactionFunc = transactionFunc; // Set the function pointer to the transaction function
    newTransaction->next = NULL; // Set the next pointer to NULL (assuming this is a new transaction)

    return newTransaction; // Return the newly created Transaction node
}
void addTransaction(Transaction** head, char* name, void (*transactionFunc)()) {
    Transaction* newTransaction = createTransaction(name, transactionFunc);
    if (*head == NULL) {
        *head = newTransaction; // Adding the transaction as the head of the list
    } else {
        Transaction* current = *head;
        while (current->next != NULL) {
            current = current->next; // Finding the last transaction in the list
        }
        current->next = newTransaction; // Adding the new transaction to the end of the list
    }
}

void displayTransactions(Transaction* head) {
    Transaction* current = head;
    int count = 1;
    printf("Available Transactions:\n"); // Displaying the header for the list of transactions
    while (current != NULL) {
        printf("%d. %s\n", count, current->name); // Displaying the transaction number and name
        current = current->next; // Moving to the next transaction in the list
        count++;
    }
    printf("\n");
}

bool validatePIN(int pin, int accountNumber) {
    int validPins[] = {1432, 1543}; // Valid PINs
    int validAccountNumbers[] = {1234, 5678}; // Valid account numbers
    int numValidAccountNumbers = sizeof(validAccountNumbers) / sizeof(validAccountNumbers[0]); // Calculating the number of valid account numbers

    for (int i = 0; i < numValidAccountNumbers; i++) {
        if (pin == validPins[i] && accountNumber == validAccountNumbers[i]) {
            return true; // PIN and account number match found
        }
    }

    return false; // No matching PIN and account number found
}
