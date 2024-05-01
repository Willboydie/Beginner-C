#include <stdio.h>
#include <stdlib.h>

int main(void){

    int Skyr_arr[] = {68, 114, 97, 103, 111, 110, 98, 111, 114, 110, 33};
    int Skyr_len = *(&Skyr_arr + 1) - Skyr_arr;

    for(int i = 0; i < Skyr_len; i++){

        char *s = &(Skyr_arr[i]);
        printf("%c", *s);
    }
    return 0;
}