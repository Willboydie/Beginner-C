/*declare packages included*/
#include <stdio.h>

/*set constant*/
const int N = 3;

int main(void)
{
    int scores[N]; /*initialise array*/

    double total = 0.0; /*initialise double*/
    for (int i = 0; i < N; i++) /*loop over the array*/
    {
        printf("tell me score %d: ", i+1);
        scanf("%d", &scores[i]); /*prompt for and read-in array elements*/

        total += scores[i]; /*add up array values*/
    }

    printf("The mean score is %0.1f", total/3); /*print the mean*/
}
