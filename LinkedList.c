
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>



#define START 1
#define END -1
#define INLOOP 1
#define ZERO 0
#define MAXCHAR 100

/*char * name;*/
typedef struct nodeele {

    int num;
    struct nodeele * next;
} NODE;

int add_node(NODE **head, int pos) {
    int postmp ;
    char choice;
    printf("Inside add_node\n");
    NODE * temp, * prev = NULL;

    if (*head == NULL && pos != START) {
        printf("add_node  --> List is empty!!\n");
        return -1 ;
    }
    while(INLOOP) {
        if ((temp = (NODE *)malloc (sizeof(NODE))) == NULL) {
            printf("add_node --> malloc failed!!\n");
            return -1;
        }
        printf("add_node --> Enter node value to be inserted\n");
        scanf(" %d", &temp->num);
        temp->next = NULL;
        if(*head == NULL && pos == START) {
            *head = temp;

        } else if (*head != NULL && pos == START) {
            temp->next = *head;
            *head = temp;

        } else {
            if(prev == NULL) {

                prev = *head;
                for(postmp=pos; postmp!=1; postmp--) {
                    if(prev->next == NULL) {
                        break;
                    } else {
                        prev = prev->next;
                    }
                }


            }
            temp->next = prev->next;
            prev->next = temp;


        }
        prev = temp;
        pos = ZERO;
        printf("Do you want to enter another element?:\n- yes -> 'y'\n- no -> n\n");

        scanf(" %c", &choice);
        if (choice != 'y') {
            break;
            printf("You entered %c. Exiting add_node\n", choice);
        }


    }
    printf("\n+++++++++++++++++++++++ add_node +++++++++++++++++++++++++++\n");
    return 0;
}

int del_node(NODE **head, int del_data) {
    printf("Inside del_node\n");

    NODE * curr, * prev;
    prev = *head;
    if (*head == NULL) {
        printf("del_node  --> Head pointer is null!!\n");
        return -1 ;
    }
    while(prev->num == del_data) {
        *head = prev->next;
        free(prev);
        prev = *head;
        if(prev == NULL)
            return 0;
    }

    while(prev->next != NULL) {
        curr = prev->next;
        if(curr->num == del_data) {
            prev->next = curr->next;
            free(curr);
        } else {
            prev = curr;
        }
    }
    printf("\n----------------------- del_node ---------------------------\n");


    return 0;
}

void print_list(NODE **head) {
    NODE * curr;
    int index = 1;

    if (*head == NULL) {
        printf("print_list --> Head pointer is null!!\n");
        return ;
    }

    printf("Inside print_list\n");
    printf("\n********************* print_list ***************************\n");
    curr = *head;
    while(curr != NULL) {
        printf(" %4d -> %d\n", index, curr->num);
        curr = curr->next;
        index++;
    }
    printf("\n************************************************************\n");

}

void quit_list(NODE **head) {
    NODE * curr, *temp;

    printf("Inside quit_list\n");

    if (*head == NULL) {
        printf("quit_list --> Head pointer is null!!\n");
        return ;
    }
    curr = *head;
    while(curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}


int main() {
    NODE **head;
    char choice;
    int pos, data;

    if ((head = (NODE **)malloc (sizeof(NODE *))) == NULL) {
        printf("main --> malloc failed!!\n");
        return -1;
    }

    while(INLOOP) {
        printf("BF -- Head Pointer *head = %p\n", *head);
        printf("Enter list operation:\n- add node/s -> 1\n- delete node/s -> 2\n- display list -> 3\n- Quit ->'q'\n");

        scanf(" %c", &choice);
        if (choice == 'q') {
            quit_list(head);
            break;
        }
        switch(choice) {
        case '1':
            printf("Enter position to insert:\n- beginning of list -> 1\n- End of list -> -1\n- Any other position in list -> position\n");
            scanf(" %d", &pos);
            add_node(head, pos);
            break;

        case '2':
            printf("Enter value of data in the node to be deleted\n");
            scanf(" %d", &data);
            del_node(head, data);
            break;

        case '3':
            print_list(head);
            break;

        case '4':

        /*
          case 5:
          case 6:
          case 7:
          case 8:
        */
        default:
            printf("Wrong choice option %c. Re-enter list operation choices\n", choice);
            break;
        }

        printf("AF -- Head Pointer *head = %p\n", *head);
    }

    printf("\n");


    return 0;
}





















