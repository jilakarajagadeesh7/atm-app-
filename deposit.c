//This code represents an ATM program implemented in C. It prompts the user to enter their account number and PIN.
//If the PIN is correct, it presents a menu of options for cash deposit, withdrawal, fund transfer, or account services.
//The user's choice is then processed accordingly. The program also includes functionality to hide the password input and limit
//the password length to four characters.
#include <stdio.h>
#include <stdlib.h>

void cashDeposit() {
    double amount;
    FILE *file;
    
    printf("valiadate notes:1.100 2.200 3.500 4.2000\n");

    // Prompt for deposit amount
    printf("Enter the amount to deposit: ");
    scanf("%lf", &amount);
    // Validate the amount (should be between 100 and 100000)
    if (amount < 100 || amount > 100000) {
        printf("Invalid amount. Deposit failed.\n");
        return;
    }

    // Perform the deposit and update account balance
    // Add your logic here

    // Save the transaction to a file
    file = fopen("transactions.txt", "a");
    if (file == NULL) {
        printf("Error opening file. Transaction not recorded.\n");
        return;
    }

    fprintf(file, "Deposit: Rs%.2lf\n", amount);
    fclose(file);

    printf("Deposit successful. Thank you!\n");
}
