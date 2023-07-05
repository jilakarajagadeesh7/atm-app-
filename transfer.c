#include <stdio.h>
#include <stdlib.h>

void fundTransfer() {
    double amount;
    int pin;
    char recipient[50];
    FILE *file;

    // Prompt for transfer amount
    printf("Enter the amount to transfer: ");
    scanf("%lf", &amount);

    // Validate the amount (should be positive)
    if (amount <= 0) {
        printf("Invalid amount. Transfer failed.\n");
        return;
    }

    // Prompt for recipient account
    printf("Enter the recipient's account: ");
    scanf("%s", recipient);

    // Prompt for PIN
    printf("Enter your PIN: ");
    if (scanf("%d", &pin) != 1) {
        printf("Invalid PIN. Transfer failed.\n");
        return;
    }

    // Perform the fund transfer and update account balances
    // Add your logic here

    // Save the transaction to a file
    file = fopen("transactions.txt", "a");
    if (file == NULL) {
        printf("Error opening file. Transaction not recorded.\n");
        return;
    }

    fprintf(file, "Transfer: Rs%.2lf to %s\n", amount, recipient);
    fclose(file);

    printf("Transfer successful. Thank you!\n");
}
