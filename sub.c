#include <stdio.h>
#include <stdlib.h>
#include "sub.h"

void cashWithdrawal() {
    printf("Performing cash withdrawal...\n");
    int amount;
    printf("Select withdrawal amount:\n");
    printf("1. Rs 100\n");
    printf("2. Rs 200\n");
    printf("3. Rs 500\n");
    printf("4. Rs 2000\n");
    printf("Enter your choice: ");
    scanf("%d", &amount);

    switch (amount) {
        case 1:
            printf("Withdrawing Rs 100...\n");
            break;
        case 2:
            printf("Withdrawing Rs 200...\n");
            break;
        case 3:
            printf("Withdrawing Rs 500...\n");
            break;
        case 4:
            printf("Withdrawing Rs 2000...\n");
            break;
        default:
            printf("Invalid choice. No withdrawal made.\n");
            break;
    }
}

void cashDeposit() {
    printf("Performing cash deposit...\n");
    int amount;
    printf("Enter the deposit amount (in Rs): ");
    scanf("%d", &amount);

    if (amount > 0 && amount <= MAX_DEPOSIT_AMOUNT) {
        printf("Depositing Rs %d...\n", amount);
    } else {
        printf("Invalid deposit amount. Please enter a value between 1 and %d (in Rs).\n", MAX_DEPOSIT_AMOUNT);
    }
}

void fundTransfer() {
    printf("Performing fund transfer...\n");
}

void accountServices() {
    printf("Performing account services...\n");
    int option;
    printf("Select an option:\n");
    printf("1. Balance Inquiry\n");
    printf("2. Mini Statement\n");
    printf("3. PIN Change\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Performing balance inquiry...\n");
            break;
        case 2:
            printf("Performing mini statement...\n");
            break;
        case 3:
            printf("Performing PIN change...\n");
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
}

void exitATM() {
    printf("Exiting ATM...\n");
    exit(0);
}

Transaction* createTransaction(char* name, void (*transactionFunc)()) {
    Transaction* newTransaction = (Transaction*)malloc(sizeof(Transaction));
    newTransaction->name = name;
    newTransaction->transactionFunc = transactionFunc;
    newTransaction->next = NULL;
    return newTransaction;
}

void addTransaction(Transaction** head, char* name, void (*transactionFunc)()) {
    Transaction* newTransaction = createTransaction(name, transactionFunc);
    if (*head == NULL) {
        *head = newTransaction;
    } else {
        Transaction* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTransaction;
    }
}

void displayTransactions(Transaction* head) {
    Transaction* current = head;
    int count = 1;
    printf("Available Transactions:\n");
    while (current != NULL) {
        printf("%d. %s\n", count, current->name);
        current = current->next;
        count++;
    }
    printf("\n");
}

bool validatePIN(int pin, int accountNumber) {
    int validPins[] = {1432, 1543}; 
    int validAccountNumbers[] = {1234, 5678}; 
    int numValidAccountNumbers = sizeof(validAccountNumbers) / sizeof(validAccountNumbers[0]);

    for (int i = 0; i < numValidAccountNumbers; i++) {
        if (pin == validPins[i] && accountNumber == validAccountNumbers[i]) {
            return true;
        }
    }

    return false;
}
