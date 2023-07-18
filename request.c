#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TRANSACTIONS 5

void statementRequest(const char* userName) {
    FILE *file;
    char transaction[1000];
    char userTransaction[MAX_TRANSACTIONS][1000];
    int transactionCount = 0;
    int totalTransactionCount = 0;

    // Open the transaction file
    file = fopen("transactions.txt", "r");
    if (file == NULL) {
        printf("Error opening file. Statement not available.\n");
        return;
    }

    // Count the total number of transactions for the user
    while (fgets(transaction, sizeof(transaction), file) != NULL) {
        if (strstr(transaction, userName) != NULL) {
            totalTransactionCount++;
        }
    }

    // Calculate the number of transactions to display
    int numTransactions = (totalTransactionCount > MAX_TRANSACTIONS) ? MAX_TRANSACTIONS : totalTransactionCount;
    int start = totalTransactionCount - numTransactions;
    int currentTransaction = 0;

    // Rewind the file
    rewind(file);

    // Find and store the last 5 transactions for the user
    while (fgets(transaction, sizeof(transaction), file) != NULL) {
        if (strstr(transaction, userName) != NULL) {
            if (currentTransaction >= start) {
                strcpy(userTransaction[currentTransaction % MAX_TRANSACTIONS], transaction);
            }
            currentTransaction++;
        }
    }

    fclose(file);

    // Print the last 5 transactions for the user
    printf("Statement for user '%s':\n", userName);
    if (numTransactions == 0) {
        printf("No transactions found for user '%s'.\n", userName);
    } else {
        for (int i = 0; i < numTransactions; i++) {
            printf("%s", userTransaction[i]);
        }
    }
}
