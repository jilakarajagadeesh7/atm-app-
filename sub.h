#ifndef SUB_H
#define SUB_H
#include<stdbool.h>

// PIN length for the ATM
#define PIN_LENGTH 4

// Maximum number of attempts allowed
#define MAX_ATTEMPTS 3

// Maximum deposit amount allowed
#define MAX_DEPOSIT_AMOUNT 100000

// Structure to represent a transaction
typedef struct Transaction {
    char* name;                         // Name of the transaction
    void (*transactionFunc)();          // Function pointer to the transaction function
    struct Transaction* next;           // Pointer to the next transaction
} Transaction;

// Function prototypes for transaction functions
void cashWithdrawal();
void cashDeposit();
void fundTransfer();
void accountServices();
void exitATM();

// Function to create a new transaction
Transaction* createTransaction(char* name, void (*transactionFunc)());

// Function to add a transaction to the linked list
void addTransaction(Transaction** head, char* name, void (*transactionFunc)());

// Function to display all available transactions
void displayTransactions(Transaction* head);

// Function to validate PIN
bool validatePIN(int pin, int accountNumber);

#endif
