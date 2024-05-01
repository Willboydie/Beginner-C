#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

// Define useful constants
#define max_word_length 50
#define correct_word 1234
#define attempt_limit 10

int main(void){

    int iter = 0;
    bool passed = false;

    while(iter < attempt_limit && !passed){
        iter ++;
        
        // Set aside a place in memory for password (i.e. create a pointer called 'password')
        char *password = malloc(max_word_length*sizeof(int));
        printf("Please Enter Your Passcode: ");
        fgets(password, max_word_length, stdin); // the pointer 'password' now points to the value submitted to the console
        printf("Value: %sNot sure? %d\nPointer?%d\n", password, *password, &password);
        // submit 'x' into the terminal as a password to terminate the program.
        if(*password == 'x'){
            return 0;
        }

        // Create a boolean pointer 
        bool *numeric = malloc(sizeof(bool));
        *numeric = true; // define the boolean value pointed to by numeric
        printf("%d", numeric);
        for(int c = 0; c < strlen(password)-1; c++){ // loop through the passwrd
            // if we find a letter alter the boolean pointed to by numeric
            if(isdigit(password[c]) == false){
                *numeric = false;
                printf("Password Must Be Numeric. Please Try again.\n");
                printf("\n");
                free(password); // Remove password from memory before the next pass
                break;
            }
        }

        // If numeric is not true ask for password again
        if(!numeric){
            free(numeric); //remove numeric from memory before the next pass
            continue;
        }

        if(strlen(password)!=5){
            printf("Password Must Be 4 Digits. Please Try again.\n");
            printf("\n");
            free(password);
            continue;
        }
        int value = atoi(password); // Convert to an integer so we can easily compare
        if(value!=correct_word){
            printf("Incorrect Password. Please Try again.\n");
            printf("\n");
            free(password);
            continue;
        }
        else{
            passed = true;
            continue;
        }
    }

    if(iter < attempt_limit){
        printf("Password Accepted. Welcome.");
    }
    else{
        printf("Too many attempts. Please try again later!");
    }
    return 0;
}