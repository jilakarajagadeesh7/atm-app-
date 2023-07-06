//This code defines a function statementRequest() that retrieves and displays the transaction statement from a file named "transactions.txt". 
//It first attempts to open the file and checks for any errors. If the file is successfully opened, 
//it reads each line of the file and prints it as part of the statement. Finally, it closes the file.


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
