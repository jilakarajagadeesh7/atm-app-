#include <stdio.h>
#include <stdlib.h>

void statementRequest() {
    FILE *file;
    char transaction[1000];

    // Open the transaction file
    file = fopen("transactions.txt", "r");
    if (file == NULL) {
        printf("Error opening file. Statement not available.\n");
        return;
    }

    // Print each transaction from the file
    printf("Statement:\n");
    while (fgets(transaction, sizeof(transaction), file) != NULL) {
        printf("%s", transaction);
    }

    fclose(file);
}
