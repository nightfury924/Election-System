#include "functions.h"

int authAdmin(){
    printf("Enter Administrative Password: ");
    char adminpass[50] = "";
    fgets(adminpass, 50, stdin);
    FILE *fptr = fopen("adminpass.txt", "r");
    if (fptr == NULL) {
        printf("Error in Authenticating.\n");
        return 0;
    }
    char passStored[50] = "";
    fgets(passStored, 50, fptr);
    fclose(fptr);
    char password[50] = "";
    hexToText(passStored, password);
    int s = strlen(password);
    int cmp = strncmp(password , adminpass,s);
    if ( cmp == 0)
    {
        return 1;
    }
    else
    {
        printf("INCORRECT PASSWORD.\n");
        return 2;
    }
}

void hexToText(char* hexInput, char* textOutput) {
    int len = strlen(hexInput);
    if ((len - 1) % 2 != 0) {
        printf("Invalid hex input.");
        return;
    }

    int i, j;
    char tmp[3];
    tmp[2] = '\0'; // set null terminator

    for (i = 0, j = 0; i < len; i += 2, j++) {
        tmp[0] = hexInput[i];
        tmp[1] = hexInput[i + 1];
        int value;
        sscanf(tmp, "%x", &value);
        if (value < 0 || value > 255) {
            printf("Invalid hex input");
            return;
        }
        textOutput[j] = (char)value;
    }

    textOutput[j-1] = '\0'; // set null terminator
}

char* textTOhex(char* text){
    int size = strlen(text);
    char *hex = (char*)calloc((size*2+1),sizeof(char));
    if (hex == NULL)
    {
        printf("Memory Allocation Failed.");
        exit(EXIT_FAILURE);
    }
    for (unsigned int i = 0; i < size; i++)
    {
        sprintf(hex + i * 2,"%02X", *(text+i));
    }
    
    hex[size * 2] = '\0';
    return hex;
}

void registerper(){
    char temp[50] = "",temp2[50] = "",key;
    int n = 0;
    voter personel;
    do
    {
        strcpy(personel.name, "");
        strcpy(personel.cnic, "");
        strcpy(personel.prof, "");
        strcpy(personel.seckey, "");
        printf("\nVoter:\n");
        printf("Enter Name: ");
        fgets(personel.name,50,stdin);
        printf("Enter Cnic: ");
        fgets(personel.cnic,14,stdin);
        fflush(stdin);
        printf("Enter Profesion: ");
        fgets(personel.prof,50,stdin);
        retry:
        printf("Enter Security Key: ");
        fgets(temp,50,stdin);
        printf("Confirm Security Key: ");
        fgets(temp2,50,stdin);
        if (strcmp(temp,temp2) == 0)
        {
            strcpy(personel.seckey,temp);
            storeRegistered(&personel,n);
        }
        else
        {
            printf("Your Keys Didn't match Try Again.\n");
            goto retry;
        }
        printf("Escape button to exit. Any other to continue.");
        key = getch();
        if (key != 27)
        {
            n++;
        }
    }while (key != 27);
    
}

void storeRegistered(voter *data,int n){
    FILE *fptr = fopen("VoterData.txt", "a");
    if (fptr == NULL) {
        printf("Error in Writing Data to Storage.\n");
        return;
    }
    fprintf(fptr,"Voter %d\n",n);
    char *security = textTOhex(data->seckey);
    fprintf(fptr,"%s%s\n%s%s\n",data->name,data->cnic,data->prof,security);
    free(security);
    fclose(fptr);
}

void clearFile(){
    char sec[] = " asd";
    FILE *fptr = fopen("VoterData.txt", "w");
    if (fptr == NULL) {
        printf("Error in Writing Data to Storage.\n");
        return;
    }
    fprintf(fptr,"");
    fclose(fptr);
}