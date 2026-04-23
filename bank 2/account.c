#include <stdio.h>
#include "Bank.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

int generateAccountNumber() {
    int r = rand() % 900000 + 100000;
    return r;
}

void createAccount() {
    struct Account acc;
    FILE *file;

    acc.accountNumber = generateAccountNumber();

    printf("\nEnter your name: ");
    scanf("%s", acc.name);

    printf("Enter your age: ");
    scanf("%d", &acc.age);

    printf("Enter Address: ");
    scanf(" %[^\n]", acc.address);

    printf("Enter Account Type (Savings/Current): ");
    scanf("%s", acc.type);

    printf("Enter Initial Balance: ");
    scanf("%f", &acc.intialBalance);

    printf("Set 4-digit PIN: ");
    scanf("%d", &acc.pin);

    file = fopen("Data.csv", "a");
    
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return; 
    }

    // FIXED: Added the PIN formatting (%d) and the acc.pin variable to the end
    fprintf(file, "%d,%s,%d,%s,%s,%.2f,%d\n", 
            acc.accountNumber, 
            acc.name, 
            acc.age, 
            acc.address, 
            acc.type, 
            acc.intialBalance,
            acc.pin); 

    printf("\nSuccess! Account %d has been created and saved to Data.csv.\n", acc.accountNumber);

    fclose(file);
}


int searchAccount(int accNo, struct Account *acc) {
    FILE *file = fopen("Data.csv", "r");
    if (file == NULL) return 0;

    while (fscanf(file, "%d,%49[^,],%d,%99[^,],%19[^,],%f,%d\n",
            &acc->accountNumber, acc->name, &acc->age,
            acc->address, acc->type, &acc->intialBalance, &acc->pin) == 7) {
        if (acc->accountNumber == accNo) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

