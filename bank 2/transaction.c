#include <stdio.h>
#include <stdlib.h>
#include "Bank.h"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

void print_header() {
    printf(CYAN);
    printf(" ___________________________\n");
    printf("|  _______________________  |\n");
    printf("| |  " BOLD "TRANSACTION SYSTEM" RESET CYAN "   | |\n");
    printf("| |_______________________| |\n");
    printf("|___________________________|\n" RESET);
}

void showTransactionMenu() {
    int choice;
    int depa, witha, transa;
    int ibal = 500; 
    struct transaction
    {
        /* data */
    };
    
    do {
        system("clear || cls"); 
        print_header();

        printf("\n" BOLD "BALANCE: " GREEN "$%d\n" RESET, ibal);
        printf("-----------------------------\n");
        printf("1) " YELLOW "Deposit\n" RESET);
        printf("2) " YELLOW "Withdraw\n" RESET);
        printf("3) " YELLOW "Transfer\n" RESET);
        printf("4) " RED "Exit\n" RESET);
        printf("-----------------------------\n");
        printf("Select: ");
        
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n'); 
            continue;
        }

        printf("\n");

        switch(choice) {
            case 1:
                printf("Amount to deposit: ");
                scanf("%d", &depa);
                ibal += depa;  
                printf(GREEN "Success! Balance: $%d\n" RESET, ibal);
                break;

            case 2:
                printf("Amount to withdraw: ");
                scanf("%d", &witha);
                if(ibal >= witha) {
                    ibal -= witha; 
                    printf(GREEN "Success! Balance: $%d\n" RESET, ibal);
                } else {
                    printf(RED "Error: Insufficient funds.\n" RESET);
                }
                break;

            case 3:
                printf("Amount to transfer: ");
                scanf("%d", &transa);
                if(ibal >= transa) {
                    ibal -= transa; 
                    printf(GREEN "Success! Balance: $%d\n" RESET, ibal);
                } else {
                    printf(RED "Error: Insufficient funds.\n" RESET);
                }
                break;

            case 4:
                printf(CYAN "System shutting down...\n" RESET);
                break;

            default:
                printf(RED "Invalid choice.\n" RESET);
        }

        if (choice != 4) {
            printf("\nPress Enter to continue...");
            getchar(); 
            getchar(); 
        }

    } while(choice != 4); 

}