//This code defines a function cashWithdrawal() that handles the process of cash withdrawal in an ATM system. 
//It prompts the user to enter an amount to withdraw and their PIN. 
//If the amount is valid (between 100 and 10,000) and the PIN is entered correctly, it performs the withdrawal, updates the account 
//balance(not implemented in the given code), and records the transaction in a file called "transactions.txt". Finally,
//it displays a success message.

#include <stdio.h>
#include <stdlib.h>

void cashWithdrawal() {
    double amount;
    int pin;
    FILE* file;
    
    printf("enter the amount between 100 to 10000\n");

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
