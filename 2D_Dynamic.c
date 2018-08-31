#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

/*
#define MAX 10
#define STRING 20
#define TSTRING "testring"


#define INLOOP 1

#define

typedef
*/

int main() {
    char ** names;
    int MAX, SZSTRING, i;
    printf("Enter number of names :");
    scanf("%d", &MAX);
    printf("pointer\"names\" :(%p)\n", names);

    names = (char**) malloc (MAX * sizeof(char *));

    for (i=0; i<MAX; i++) {
        printf("Enter size of name %d :",i+1);
        scanf("%d", &SZSTRING);
        names[i] = (char*) malloc ((SZSTRING + 1) * sizeof(char));
//   names[i][SZSTRING] = '\0';
        printf(" %d ** Address:(%p), *char pointer : (%p)\n",i+1, &names[i], names[i]);
    }

    for (i=0; i<MAX; i++) {
        printf("Enter name %d :",i+1);
        scanf("%s", names[i]);
        printf("len of string %d : %d\n",i+1,strlen(names[i]));
    }

    printf("------------------ names[MAX][SZSTRING] = names[%d][%d] = \'%c\'\n",MAX-1 ,0, names[MAX-1][SZSTRING-1]);


    for (i=0; i<MAX; i++) {
        printf("%d : \"%s\" (%p)\n",i+1,names[i], &names[i]);
        free(names[i]);
    }
    free(names);
    return 0;
}
