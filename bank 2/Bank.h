#ifndef BANK_H
#define BANK_H

struct Account {
    int accountNumber;
    char name[50];
    int age;
    char address[100];
    char type[20];
    float intialBalance;
    int pin;
};

void createAccount();
void displayAccount();
void modifyAccount();
void deleteAccount();

void depositMoney();
void withdrawMoney();
void transferMoney();
void showTransactionMenu();

int loginAccount();
int adminLogin();

int saveAccount(struct Account acc);
int searchAccount(int accNo, struct Account *acc);
int updateAccount(struct Account acc);
int deleteAccountRecord(int accNo);


#endif