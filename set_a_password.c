#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define max_word_size 20

int main(int argC, char *argV[]) 
{
    /* Allocate memory and check if okay. */
    char *password = malloc(max_word_size*sizeof(int));

    if (password == NULL) {
        printf("No memory\n");
        return 0;
    }

    printf("Set a password...");

    /* Get the name, with size limit. */
    fgets(password, max_word_size, stdin);

    /* Remove trailing newline, if there. */
    if (strlen(password) > 0  &&  password[strlen(password) - 1] == '\n')
         password[strlen(password) - 1] = '\0';

    printf("%s is an acceptable password.", password);
    /* Free memory and exit. */
    free(password);
    return 0;
}