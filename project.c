#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store account details
struct Account {
    int accountNumber;
    char name[100];
    float balance;
};

// Function prototypes
void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
void modifyAccount();
void menu();

// Global variables
struct Account accounts[100];
int accountCount = 0;

int main() {
    menu();
    return 0;
}

// Function to display the menu
void menu() {
    int choice;
    do {
        printf("\nBank Management System\n");
        printf("1. Create a New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Account Balance\n");
        printf("5. Modify Account Details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                modifyAccount();
                break;
            case 6:
                printf("Thank you for using our Bank Management System!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
}

// Function to create a new account
void createAccount() {
    struct Account newAccount;

    printf("\nEnter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
}

// Function to deposit money
void depositMoney() {
    int accountNumber;
    float amount;
    int found = 0;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            found = 1;
            printf("Enter the amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Amount deposited successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Account not found!\n");
    }
}

// Function to withdraw money
void withdrawMoney() {
    int accountNumber;
    float amount;
    int found = 0;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            found = 1;
            printf("Enter the amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("Amount withdrawn successfully!\n");
            } else {
                printf("Insufficient balance!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Account not found!\n");
    }
}

// Function to check account balance
void checkBalance() {
    int accountNumber;
    int found = 0;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            found = 1;
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Current Balance: %.2f\n", accounts[i].balance);
            break;
        }
    }

    if (!found) {
        printf("Account not found!\n");
    }
}

// Function to modify account details
void modifyAccount() {
    int accountNumber;
    int found = 0;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            found = 1;
            printf("Enter new name: ");
            scanf("%s", accounts[i].name);
            printf("Account details updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Account not found!\n");
    }
}