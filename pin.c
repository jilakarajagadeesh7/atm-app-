#include <stdio.h>

void changePIN() {
    int oldPIN, newPIN;

    // Prompt for old PIN
    printf("Enter your old PIN: ");
    if (oldPIN){
        printf("Invalid PIN. PIN change failed.\n");
        return;
    }

    // Prompt for new PIN
    printf("Enter your new PIN: ");
    if (newPIN) {
        printf("Invalid PIN. PIN change failed.\n");
        return;
    }

    // Update the PIN in the system
    // Add your logic here

    printf("PIN change successful. Thank you!\n");
}