#include "functions.h"


int main(){
    printf("\t\tELECTION REGISTRATION\n");
    int auth = authAdmin();
    if (auth == 0 || auth == 2)
    {
        printf("Authentication Failed.");
        return 0;
    }
    clearFile();
    registerper();
    printf("\nVoters Registered Successfully.");
    getch();
    return 0;
}
