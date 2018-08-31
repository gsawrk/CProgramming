#include <stdio.h>
#include <stdlib.h>

#define T 1
#define F 0

int n;

int * get_input() ;
int bubblesort_ascend(int * input) ;
int bubblesort_descend(int * input) ;
void display(int * input) ;


int main() {

    int  *sort;

    printf("main BEFORE=== --- %d <- %p-- num %d\n", *sort, sort, n);

    sort = get_input();
    printf("main === --- %d <- %p-- num %d\n", *sort, sort, n);
    printf("\n Integers before sorting: \n");
    display(sort);
    bubblesort_ascend(sort );
    bubblesort_descend(sort );
    printf("\n Integers after sorting: \n");
    display(sort);
    return 0;
}

int bubblesort_ascend(int * input) {

    int i, j, temp;
    char swap;
    printf("********************* In ascending order ************************\n");


    for(i=0; i< n-1; i++) {
        swap = F;
        for(j=0; j<n-i-1; j++) {
            printf("Pass%d Iter%d -> ",i,j);
            display(input);
            if(*(input+j)> *(input+j+1)) {
                temp = *(input+j);
                *(input+j) = *(input+j+1);
                *(input+j+1) = temp;
                swap = T;
            }
        }
        if ( swap == F)
            break;
    }
    printf("*****************************************************************\n");

    return 0;
}

int bubblesort_descend(int * input) {

    int i, j, temp;
    char swap;

    printf("********************* In descending order ************************\n");

    /* This loop is for number of passes required for complete sorting.
     * Max passes = Number of input numbers
     */
    for(i=0; i< n-1; i++) {

        /* swap: This is to check if a target number is swapped during the current pass.
         * If it is not swapped, it means the list is sorted and the function returns.However even after the list is sorted ,
         * an extra pass is required to confirm the same.
         */
        swap = F;

        /* This loop is for shifts/swaps each number undergoes during its comparison with neighbours.
         * Max shifts depends on current position of the number in its turn
         * After each iteration, a target number will reach its target postion
         * So, in the next pass the number of iterations depends on number of input numbers still un-sorted
         */

        for(j=0; j<n-i-1; j++) {
            printf("Pass%d Iter%d -> ",i,j);
            display(input);
            if(*(input+j)< *(input+j+1)) {
                temp = *(input+j);
                *(input+j) = *(input+j+1);
                *(input+j+1) = temp;
                swap = T;
            }
        }
        if ( swap == F)
            break;
    }
    printf("*****************************************************************\n");

    return 0;
}
/**/

int * get_input() {
    int i;
    int *input;
    printf("\n\n Enter integer value for total no.s of elements to be sorted: ");
    scanf("%d",&n);
    if ((input = (int *) calloc(n, sizeof(int))) == NULL)
        return 0;
    for( i=0; i<n; i++)  {
        printf("\n\n Enter integer value for element no.%d : ",i+1);
        scanf("%d",input+i);
        printf("--- %d <- %p--\n", *(input+i), input+i);
    }

    return input;
}

void display(int * sort) {
    int i;
    for( i=0; i<n; i++)  {
        printf("%5d ",*(sort+i));
    }
    printf("\n");
}

/*
Sample Output:

main BEFORE=== --- 1416572 <- 0xb7776ff4-- num 0


 Enter integer value for total no.s of elements to be sorted: 5


 Enter integer value for element no.1 : 23
--- 23 <- 0x8cab008--


 Enter integer value for element no.2 : 3
--- 3 <- 0x8cab00c--


 Enter integer value for element no.3 : 45
--- 45 <- 0x8cab010--


 Enter integer value for element no.4 : 75
--- 75 <- 0x8cab014--


 Enter integer value for element no.5 : 54
--- 54 <- 0x8cab018--
main === --- 23 <- 0x8cab008-- num 5

 Integers before sorting:
   23     3    45    75    54
********************* In ascending order ************************
Pass0 Iter0 ->    23     3    45    75    54
Pass0 Iter1 ->     3    23    45    75    54
Pass0 Iter2 ->     3    23    45    75    54
Pass0 Iter3 ->     3    23    45    75    54
Pass1 Iter0 ->     3    23    45    54    75
Pass1 Iter1 ->     3    23    45    54    75
Pass1 Iter2 ->     3    23    45    54    75
*****************************************************************
********************* In descending order ************************
Pass0 Iter0 ->     3    23    45    54    75
Pass0 Iter1 ->    23     3    45    54    75
Pass0 Iter2 ->    23    45     3    54    75
Pass0 Iter3 ->    23    45    54     3    75
Pass1 Iter0 ->    23    45    54    75     3
Pass1 Iter1 ->    45    23    54    75     3
Pass1 Iter2 ->    45    54    23    75     3
Pass2 Iter0 ->    45    54    75    23     3
Pass2 Iter1 ->    54    45    75    23     3
Pass3 Iter0 ->    54    75    45    23     3
*****************************************************************

 Integers after sorting:
   75    54    45    23     3
*/
