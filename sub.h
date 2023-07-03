#ifndef SUB_H
#define SUB_H
#include<stdbool.h>
#define PIN_LENGTH 4
#define MAX_ATTEMPTS 3
#define MAX_DEPOSIT_AMOUNT 100000

typedef struct Transaction {
    char* name;
    void (*transactionFunc)();
    struct Transaction* next;
} Transaction;

void cashWithdrawal();
void cashDeposit();
void fundTransfer();
void accountServices();
void exitATM();

Transaction* createTransaction(char* name, void (*transactionFunc)());
void addTransaction(Transaction** head, char* name, void (*transactionFunc)());
void displayTransactions(Transaction* head);
bool validatePIN(int pin, int accountNumber);

#endif
