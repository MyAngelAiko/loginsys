#include <stdio.h>

struct login {
    char fname[20];
    char lname[20];
    char username[30];
    char password[30];
};

int main(void) {
    int option;
    printf("Press '1' to Register\nPress '2' to Login\n\n");
    scanf("%d",&option);
}