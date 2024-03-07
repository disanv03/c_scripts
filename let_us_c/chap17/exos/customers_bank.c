/* Create a structure to specify data of customers in a bank.
 * The data to be stored is: Account number, Name, Balance.
 * (1) write a function to print the account number & name & balance(below 100)
 * (2) request for withdrawal or deposit, the form contains the fields
 * - Acount number, amount, code (1 for deposit, 0 for withdrawal)
 *
 *   If on withdrawal the balance fall below 100 write:
 *   "The balance is insufficient for the specified withdrawal"
 */

#include <stdio.h>

/* function for withdrawal or deposit */
void action(long int, int, int);

/* print the balance below 100 */
void below100();

struct acc_holder {
    long int acc_num;
    char name[30];
    int bal;
} bank[200] = { 1, "Siraj", 10000,
    2, "Azad", 120000,
    3, "Deepak", 99,
    14, "Rihan", 33,
    5, "Rahul", 200
};

int main() {
    int accnum, amount, code;
    printf("\nEnter your account number: ");
    scanf("%d", &accnum);
    printf("Enter 1 for deposit and 0 for withdrawal: ");
    scanf("%d", &code);

    if (code) {
        printf("\nEnter amount for deposit: ");
        scanf("%d", &amount);
    } else {
        printf("\nEnter amount to withdraw: ");
        scanf("%d", &amount);
    }

    action(accnum, amount, code);

    printf("\nAll members with account balance less than 100:");
    below100();

    return 0;
}

void below100() {
    int i;
    for (i = 0; i < 200; i++) {
        if (bank[i].bal < 100 && bank[i].bal > 0) {
            printf("\nName: %s", bank[i].name);
            printf("\n Account Number : %ld\n", bank[i].acc_num);
        }
    }
}

void action(long int accnum, int amount, int code) {
    int account_found = 0;
    int i;
    for (i = 0; i < 200; i++) {
        if (bank[i].acc_num == accnum) {
            account_found = 1;
            break;
        }
    }

    if (!account_found) {
        printf("\nAccount number %ld not found.", accnum);
        return;
    }

    if (code == 0) {
        if (bank[i].bal - amount < 100) {
            printf("\nThe balance is insufficient for this whitdraw");
        } else {
            bank[i].bal -= amount;
            printf("\nWithdrawal succesful. New balance is: %d", bank[i].bal);
        }
    }
    else if (code == 1) {
        bank[i].bal += amount;
        printf("\nDeposit succesful. New balance is: %d", bank[i].bal);
    }
    else {
        printf("\nInvalid operation code.");
    }
}

