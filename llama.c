/*Packages included*/ 
#include <stdio.h>
#include <stdlib.h>

/*Initialise main function*/
int main(void)
{
    int start_pop; /*Initialise integer*/
    do
    {
        /*Prompt for and read a starting population*/
        printf("Starting population: ");
        scanf("%d", &start_pop);
        
    }
    while(start_pop < 9); /*Keep promtoping until this is >9*/

    int end_pop = 0; /*initialise a second int*/
    do
    {
        printf("End population: ");
        scanf("%d", &end_pop);
    } 
    while (end_pop < start_pop); /*Keep prompting until one is given greater than start_pop*/

    double pop_dub = (double)start_pop; /*convert to a double*/
    int count = 0; /*initialise a count*/
    while (pop_dub < end_pop) /*until we reach end_pop*/
    { 
        count++; /*record the interation*/
        pop_dub = 13.0/12.0 * pop_dub; /*increase the population by given proportion*/
    }

    /*print the number of years it takes for sufficient population growth*/
    printf("Starting from an initial population of %d llamas, after %d years, we will have a population of %0.1f, greater than the target of %d.", start_pop, count, pop_dub, end_pop);
}