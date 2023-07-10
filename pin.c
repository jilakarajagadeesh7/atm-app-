//This code defines a function changePIN() that allows a user to change their PIN. 
//It presents two options: changing the PIN with the old PIN or changing the PIN with the account number and OTP.
//It prompts the user for the required information, performs validation checks, and updates the PIN accordingly if all checks pass.

#include <stdio.h>
#include <stdbool.h>

bool validatePositiveIntegerInput(int input) {
    if (input < 0) {
        printf("Invalid input. Negative values are not allowed.\n");
        return false;
    }
    if (getchar() != '\n') {
        printf("Invalid input. Alphabets and special characters are not allowed.\n");
        while (getchar() != '\n');
        return false;
    }
    return true;
}

void changePIN() {
    int option;
    printf("Choose an option:\n");
    printf("1. Change PIN with old PIN\n");
    printf("2. Change PIN with account number and OTP\n");
    printf("Enter your option: ");
    if (scanf("%d", &option) != 1 || !validatePositiveIntegerInput(option)) {
        printf("Invalid option. PIN change failed.\n");
        return;
    }

    if (option == 1) {
        int oldPIN, newPIN;
        // Prompt for old PIN
        printf("Enter your old PIN: ");
        if (scanf("%d", &oldPIN) != 1 || !validatePositiveIntegerInput(oldPIN)) {
            printf("Invalid PIN. PIN change failed.\n");
            return;
        }

        // Validate the old PIN
        // Add your old PIN validation logic here
        // ...

        // Prompt for new PIN
        printf("Enter your new PIN: ");
        if (scanf("%d", &newPIN) != 1 || !validatePositiveIntegerInput(newPIN)) {
            printf("Invalid PIN. PIN change failed.\n");
            return;
        }

        // Update the PIN in the system if the old PIN is valid
        // Add your PIN update logic here
        // ...

        printf("PIN change successful. Thank you!\n");
    } else if (option == 2) {
        int accountNumber, newPIN, otp;

        // Prompt for account number
        printf("Enter your account number: ");
        if (scanf("%d", &accountNumber) != 1 || !validatePositiveIntegerInput(accountNumber)) {
            printf("Invalid account number. PIN change failed.\n");
            return;
        }

        // Validate the account number
        // Add your account number validation logic here
        // ...

        // Generate and send OTP to registered mobile number
        // Add your OTP generation and sending logic here
        // ...

        // Prompt for OTP
        printf("Enter OTP: ");
        if (scanf("%d", &otp) != 1 || !validatePositiveIntegerInput(otp)) {
            printf("Invalid OTP. PIN change failed.\n");
            return;
        }

        // Verify the OTP
        // Add your OTP verification logic here
        // ...

        // Prompt for new PIN
        printf("Enter your new PIN: ");
        if (scanf("%d", &newPIN) != 1 || !validatePositiveIntegerInput(newPIN)) {
            printf("Invalid PIN. PIN change failed.\n");
            return;
        }

        // Update the PIN in the system if OTP verification succeeds
        // Add your PIN update logic here
        // ...

        printf("PIN change successful. Thank you!\n");
    } else {
        printf("Invalid option. PIN change failed.\n");
    }
}
