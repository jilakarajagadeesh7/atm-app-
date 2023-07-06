//This code defines a function changePIN() that handles the process of changing the PIN in an ATM system.
//It prompts the user to enter their old and new PIN. However, the code provided does not correctly validate the old or new PIN. 
//It displays an error message regardless of the input. The logic for updating the PIN in the system is missing in the given code. 
//Finally, it prints a success message regardless of the changes made.
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
