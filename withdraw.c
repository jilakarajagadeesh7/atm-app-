//This code defines a function cashWithdrawal() that allows a user to withdraw money from an account. 
//It prompts the user to enter an amount between 100 and 10,000, their PIN, and an OTP if the amount exceeds 10,000. 
//It performs basic validation and saves the transaction to a file named "transactions.txt".
#include <stdio.h>
#include <stdlib.h>

void cashWithdrawal() {
    double amount;
    int pin, otp;
    FILE* file;
    
    printf("Enter the amount between 100 to 10000\n");

    // Prompt for withdrawal amount
    printf("Enter the amount to withdraw: ");
    scanf("%lf", &amount);

    // Validate the amount (should be between 100 and 10,000)
    if (amount < 100 || amount > 10000) {
        printf("Invalid amount. Withdrawal failed.\n");
        return;
    }

    // Prompt for PIN
    printf("Enter your PIN: ");
    if (scanf("%d", &pin) != 1) {
        printf("Invalid PIN. Withdrawal failed.\n");
        return;
    }

    // Check if amount exceeds 10,000 and prompt for OTP
    if (amount >=10000) {
        printf("Enter OTP: ");
        if (scanf("%d", &otp) != 1) {
            printf("Invalid OTP. Withdrawal failed.\n");
            return;
        }
        // Perform OTP verification logic here
        // ...
    }

    // Perform the withdrawal and update account balance
    // Add your logic here

    // Save the transaction to a file
    file = fopen("transactions.txt", "a");
    if (file == NULL) {
        printf("Error opening file. Transaction not recorded.\n");
        return;
    }

    fprintf(file, "Withdrawal: Rs%.2lf\n", amount);
    fclose(file);

    printf("Withdrawal successful. Thank you!\n");
}
