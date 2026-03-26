#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct login {
    char fname[20];
    char lname[20];
    char username[30];
    char password[30];
};

void login (void);
void registration (void);

int main(void) {
    int option;
    printf("Press '1' to Register\nPress '2' to Login\n\n");
    scanf("%d",&option);
    if (option == 1) {
        system("CLS");
        registration();
    }
    else if (option == 2) {
        system("CLS");
        login();
    }
}

void registration() {
    FILE *fptr;
    fptr = fopen("login.txt","w");
    if (fptr == NULL) {
        fputs("Error at opening file!", stderr);
        exit(1);
    }
    struct login l;

    printf("\nEnter your first name:\n");
    scanf("%s",l.fname);
    printf("\nEnter your last name:\n");
    scanf("%s",l.lname);
    printf("\nThank you! Now please enter the username you wish to use (max 30 character with no special characters):\n");
    scanf("%s",l.username);
    printf("\nnow please enter a password (same requirements):");
    scanf("%s",l.password);

    fwrite(&l, sizeof(l), 1, fptr);
    fclose(fptr);

    printf("\nConfirming details...\n...\nWelcome, %s!\n\n",l.fname);
    printf("\nRegistration Successful!\n");
    printf("Press any key to continue...");
    getchar();
    system("CLS");
    login();
}


void login() {
    char username[30],password[30];
    struct login l;

    printf("\nPlease enter your login credentials below:\n\n");
    printf("\nPlease enter your username:\n");
    scanf("%s",username);
    printf("\nPlease enter your password:\n");
    scanf("%s",password);

    while(fread(&l, sizeof(l), 1, stdin) == 1) {
        if(strcmp(l.fname,username)==0 && strcmp(l.lname,password)==0) {
            printf("\nLogin Successful!\n");
        }
        else {
            printf("\nOne of ur username or password is incorrect. try again!");
            login();
        }
    }
    fclose(stdin);
    return;


    };



