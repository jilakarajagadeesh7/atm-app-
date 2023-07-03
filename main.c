#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sub.h"

int main() {
    Transaction* transactionList = NULL;
    addTransaction(&transactionList, "Cash Withdrawal", cashWithdrawal);
    addTransaction(&transactionList, "Cash Deposit", cashDeposit);
    addTransaction(&transactionList, "Fund Transfer", fundTransfer);
    addTransaction(&transactionList, "Account Services", accountServices);
    addTransaction(&transactionList, "Exit", exitATM);
    
    displayTransactions(transactionList);
    int attempts = 0;
    bool authenticated = false;
    while (attempts < MAX_ATTEMPTS) {
        int accountNumber, pin;
        printf("Enter your account number: ");
        scanf("%d", &accountNumber);
        printf("Enter your PIN: ");
        scanf("%d", &pin);
        attempts++;

        if (validatePIN(pin, accountNumber)) {
            authenticated = true;
            break;
        } else {
            printf("Invalid account number or PIN. Please try again.\n");
        }
    }

    if (!authenticated) {
        printf("Maximum PIN attempts exceeded. Exiting...\n");
        return 0;
    }
    int choice;
    while (1) {
        printf("Enter transaction number: ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 5) {
            Transaction* current = transactionList;
            for (int i = 1; i < choice; i++) {
                current = current->next;
            }
            current->transactionFunc();
        } else if (choice == 6) {
            exitATM();
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
