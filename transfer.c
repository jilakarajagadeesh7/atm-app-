#include <stdio.h>
#include "sub.h"

void fundTransfer(int *balance) {
    double amount;
    int pin;
    char recipient[50];
    FILE *file;

    printf("Enter the amount to transfer: ");
    scanf("%lf", &amount);
    // Validate the amount (should be positive and less than or equal to the account balance)
    if (amount <= 0 || amount > *balance) {
        printf("Invalid amount. Transfer failed.\n");
        return;
    }

    printf("Enter the recipient's account: ");
    scanf("%s", recipient);

    printf("Enter your PIN: ");
    if (scanf("%d", &pin) != 1) {
        printf("Invalid PIN. Transfer failed.\n");
        return;
    }

    // Perform the fund transfer and update account balances
    *balance -= (int)amount;

    // Save the transaction to a file
    file = fopen("transactions.txt", "a");
    if (file == NULL) {
        printf("Error opening file. Transaction not recorded.\n");
        return;
    }

    fprintf(file, "Transfer: Rs%.2lf to %s\n", amount, recipient);
    fclose(file);

    printf("Transfer successful. Thank you!\n");

    // Display the updated account balance
    printf("Your updated account balance is: Rs%d\n", *balance);
}
