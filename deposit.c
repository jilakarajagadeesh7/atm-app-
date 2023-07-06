//This code defines a function cashDeposit() that handles the process of cash deposit in an ATM system.
//It prompts the user to enter an amount to deposit. If the amount is valid (between 100 and 100,000), it performs the deposit,
//updates the account balance (not implemented in the given code), and records the transaction in a file called "transactions.txt". 
//Finally, it displays a success message.

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
