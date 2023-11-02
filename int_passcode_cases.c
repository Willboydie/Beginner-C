#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h> /*Declare packages*/

#define max_word_size 100 /*Define max password length -1 that will be read by fgets*/


int main(void){

    /*dynamically allot memory for the inputted passcode*/
    char *passcode = malloc(max_word_size*sizeof(int));

    /*check if the memory is available*/
    if (passcode == NULL) {
        printf("No memory\n");
        return 0;
    }

    bool numeric; /*declare boolean value*/

    do{
        numeric = true; /*initialise as true (assuming the input will be numeric)*/
        
        printf("Enter your passcode. Must be 4 numbers: "); /*Prompt for passcode*/

        /* Scan the passcode, with size limit. */
        fgets(passcode, max_word_size, stdin);

        /* Remove trailing newline, if there. */
        if (strlen(passcode) > 0  &&  passcode[strlen(passcode) - 1] == '\n')
            passcode[strlen(passcode) - 1] = '\0';

        /*Loop over each character in the string to check they are all numeric using isdigit()*/
        for(int i = 0; i < strlen(passcode); i++){

            if(isdigit(passcode[i]) == false){ /*Check character is numeric*/
                numeric = false;
                break; /*if it isn't numeric, stop looping and declare the string non-numeric*/
                }
            }
        } 
        while(numeric == false | strlen(passcode) != 4); /*Prompt for passcode again if not a 4-digit number*/
        
    int code = atoi(passcode); /*if it is a 4-digit number, convert the string to an integer*/

    switch(code){

        case 1234: /*If 1234 was inputted, print welcome message*/
            printf("Passcode accepted. You may enter.");
            break;

        default: /*otherwise assert incorrect*/
            printf("Incorrect passcode. Goodbye.\n");
            break;
    }

    free(passcode); /*remove the variable from memory, allowing the preventing infinite iteration of the do-while loop if ran twice*/
}