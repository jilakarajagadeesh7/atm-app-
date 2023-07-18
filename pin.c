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

        // Update the PIN in the user_info.txt file
        FILE* file = fopen("user_info.txt", "r");
        FILE* tempFile = fopen("temp.txt", "w");
        if (file == NULL || tempFile == NULL) {
            printf("Error updating PIN. Please try again.\n");
            return;
        }

        char name[50];
        char phoneNumber[15];
        int accountNumber, pinNumber;
        bool pinUpdated = false;

        while (fscanf(file, "%s %s %d %d", name, phoneNumber, &accountNumber, &pinNumber) != EOF) {
            if (pinNumber == oldPIN) {
                fprintf(tempFile, "%s %s %d %d\n", name, phoneNumber, accountNumber, newPIN);
                pinUpdated = true;
            } else {
                fprintf(tempFile, "%s %s %d %d\n", name, phoneNumber, accountNumber, pinNumber);
            }
        }

        fclose(file);
        fclose(tempFile);

        if (pinUpdated) {
            remove("user_info.txt");
            rename("temp.txt", "user_info.txt");
            printf("PIN change successful. Thank you!\n");
        } else {
            remove("temp.txt");
            printf("Invalid old PIN. PIN change failed.\n");
        }
    } else if (option == 2) {
        // ...
    } else {
        printf("Invalid option. PIN change failed.\n");
    }
}
