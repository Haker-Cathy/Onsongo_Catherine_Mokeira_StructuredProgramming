#include <stdio.h>
#include <stdlib.h>

int balance = 1000;
void CheckBalance();
void deposit(int amount);
void withdraw(int amount);

int main(){
   int storedPIN = 3456;
   int UserPIN;
   int attempts = 1;
   int maxattempts = 3;
   int choice;
   int amount;

   while (attempts <= maxattempts){
       printf("Please input your PIN: \n");
       scanf("%d", &UserPIN);

       if (UserPIN == storedPIN){
        printf("ACCESS GRANTED\n");

        do{
            printf("\n    MAIN MENU    \n");
            printf("1.Check my balance.\n");
            printf("2.Deposit my money.\n");
            printf("3.Withdraw my money.\n");
            printf("4.Exit.\n");
            printf("ENTER YOUR CHOICE: \n");
            scanf("%d", &choice);

            switch(choice){
                case 1:
                    CheckBalance();
                    break;
                case 2:
                    printf("Enter amount to be deposited: .\n");
                    scanf("%d",&amount);
                    deposit(amount);
                    break;
                case 3:
                    printf("Enter amount to be withdrawn: .\n");
                    scanf("%d",&amount);
                    withdraw(amount);
                    break;
                case 4:
                    printf("Thank You for using our ATM!Exiting session...\n");
                    break;
                default:
                    printf("INVALID CHOICE! PLEASE TRY AGAIN.\n");
            }
        }while (choice != 4);
       }
       else {
        attempts++;
        printf("INCORRECT PIN. ATTEMPTS LEFT: %d\n", maxattempts - attempts);
       }
   }
   printf("INCORRECT PIN...MAXIMUM USE OF ATTEMPTS. ACCESS DENIED!\n");
   return 0;
}

void CheckBalance() {
    printf("Your current Balance is: Ksh.%d", balance);
}

void deposit(int amount) {
    if (amount > 0) {
        balance += amount;
        printf("Successfully deposited %d Kenyan Shillings\n", amount);
        CheckBalance();
    } else {
        printf("Invalid deposit amount.\n");
    }
}

void withdraw(int amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        printf("Successfully withdrew %d Kenyan Shillings\n", amount);
        CheckBalance();
    } else if (amount > balance) {
        printf("Insufficient balance.Withdrawal denied!\n");
    } else {
        printf("Invalid withdrawal amount.\n");
    }
}
