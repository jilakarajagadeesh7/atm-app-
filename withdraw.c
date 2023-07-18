#include <stdio.h>
#include "sub.h"

void cashWithdrawal(int *balance) {
    double amount;
    FILE *file;

    printf("Enter the amount to withdraw: ");
    scanf("%lf", &amount);
    // Validate the amount (should be positive and less than or equal to the account balance)
    if (amount <= 0 || amount > *balance) {
        printf("Invalid amount. Withdrawal failed.\n");
        return;
    }

    // Perform the withdrawal and update account balance
    *balance -= (int)amount;

    // Save the transaction to a file
    file = fopen("transactions.txt", "a");
    if (file == NULL) {
        printf("Error opening file. Transaction not recorded.\n");
        return;
    }

    fprintf(file, "Withdrawal: Rs%.2lf\n", amount);
    fclose(file);

    printf("Withdrawal successful. Thank you!\n");

    // Display the updated account balance
    printf("Your updated account balance is: Rs%d\n", *balance);
}
