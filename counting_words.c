#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){

    char text_message[] = "  Hey  bro!   Passionate Dog  tonight?  ";
    int message_len = *(&text_message + 1) - text_message; // trick to find the length of array/string

    bool bools[] = {true, false};
    bool *last_was_space = &(bools[0]);

    int indiv_words = 0;

    for(int i = 0; i < message_len-1; i++){

       if (text_message[i] != ' ' && *last_was_space){
            indiv_words ++;
            last_was_space = &(bools[1]);
        }

        if (text_message[i] == ' '){
            last_was_space = &(bools[0]);
        }
    }

    printf("The text has %d individual words.", indiv_words);
    return 0;
}