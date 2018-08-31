
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
typedef struct node {

    int num;
    struct node * next;
} NODE;

NODE *head;

int create_list() {
    int pos_tmp ;
    char choice;

    NODE * temp, * prev = NULL;

    printf("\n+++++++++++++++++++++++ create_list +++++++++++++++++++++++++++\n");

    if ((temp = (NODE *)malloc (sizeof(NODE))) == NULL) {
        printf("add_node --> malloc failed!!\n");
        return -1;
    }
    printf("create_list --> Enter node value \n");
    scanf(" %d", &temp->num);
    temp->next = NULL;

    head = temp;
    prev = head;

    while(INLOOP) {
        printf("Do you want to enter another element?:\n- yes -> 'y'\n- no -> n\n");

        scanf(" %c", &choice);
        if (choice != 'y') {
            printf("You entered %c. Exiting add_node\n", choice);
            break;
        }

        if ((temp = (NODE *)malloc (sizeof(NODE))) == NULL) {
            printf("add_node --> malloc failed!!\n");
            return -1;
        }
        printf("add_node --> Enter node value to be inserted\n");
        scanf(" %d", &temp->num);
        temp->next = NULL;

        prev->next = temp;
        prev = temp;

    }
    printf("\n************************************************************\n");
    return 0;
}

int add_node() {
    int pos, pos_tmp ;
    char choice;
    printf("\n+++++++++++++++++++++++ add_node +++++++++++++++++++++++++++\n");
    NODE * temp, * prev = head;

    if (head == NULL) {
        printf("add_node  --> List is empty!!\n");
    } else {

        if ((temp = (NODE *)malloc (sizeof(NODE))) == NULL) {
            printf("add_node --> malloc failed!!\n");
            return -1;
        }
        printf("Enter position to insert:\n- beginning of list -> 1\n- End of list -> -1\n- Any other position in list -> position\n");
        scanf(" %d", &pos);

        printf("add_node --> Enter node value to be inserted\n");
        scanf(" %d", &temp->num);

        if (pos == START) {
            temp->next = head;
            head = temp;
        } else {
            if (pos == END)  {
                while(prev->next != NULL) {
                    prev = prev->next;
                }
            } else {
                for(pos_tmp=1; pos_tmp < pos - 1; pos_tmp++)
                    prev = prev->next;
            }
            temp->next = prev->next;
            prev->next = temp;

        }
    }
    return 0;
}

int del_data() {
    printf("\n+++++++++++++++++++++++ del_data +++++++++++++++++++++++++++\n");

    NODE * curr, * prev;
    int data;
    prev = head;
    if (head == NULL) {
        printf("del_node  --> Head pointer is null!!\n");
        return -1 ;
    }

    printf("Enter value of data in the node to be deleted\n");
    scanf(" %d", &data);

    while(prev->num == data) {
        head = prev->next;
        free(prev);
        prev = head;
        if(prev == NULL)
            return 0;
    }

    while(prev->next != NULL) {
        curr = prev->next;
        if(curr->num == data) {
            prev->next = curr->next;
            free(curr);
        } else {
            prev = curr;
        }
    }
    printf("\n----------------------- del_data ---------------------------\n");


    return 0;
}


int del_pos() {

    NODE * curr, * prev;
    int pos, pos_tmp ;

    printf("\n+++++++++++++++++++++++ del_pos +++++++++++++++++++++++++++\n");


    prev = curr = head;
    if (head == NULL) {
        printf("del_node  --> Head pointer is null!!\n");
        return -1 ;
    }
    printf("Enter position to insert:\n- beginning of list -> 1\n- End of list -> -1\n- Any other position in list -> position\n");
    scanf(" %d", &pos);

    if(pos == START) {
        head = prev->next;
        curr = prev;
    } else if (pos == END) {
        while(curr->next != NULL) {
            prev = curr;
            curr = prev->next;
        }
        prev->next = NULL;
    } else {

        for(pos_tmp=1; pos_tmp < pos - 1; pos_tmp++) {
            prev = prev->next;
            if (prev->next == NULL) {
                printf("No elmenths  in that position in list\n");
                return -1 ;

            }
        }

        curr = prev->next;
        prev->next = curr->next;
    }
    free(curr);
    printf("\n----------------------- del_pos ---------------------------\n");


    return 0;
}


void print_list() {
    NODE * curr;
    int index = 1;

    if (head == NULL) {
        printf("print_list --> Head pointer is null!!\n");
        return ;
    }


    printf("\n********************* print_list ***************************\n");
    curr = head;
    while(curr != NULL) {
        printf(" %4d -> %d\n", index, curr->num);
        curr = curr->next;
        index++;
    }
    printf("\n************************************************************\n");

}

void quit_list() {
    NODE * curr, *temp;

    printf("\n********************* quit_list ***************************\n");

    if (head == NULL) {
        printf("quit_list --> Head pointer is null!!\n");
        return ;
    }
    curr = head;
    while(curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    printf("\n************************************************************\n");
}


int main() {

    char choice;
    int pos, data;

    if ((head = (NODE *)malloc (sizeof(NODE))) == NULL) {
        printf("main --> malloc failed!!\n");
        return -1;
    }

    while(INLOOP) {
        printf("BF -- Head Pointer *head = %p\n", head);
        printf("Enter list operation:\n- create list -> 1\n- add node -> 2\n- delete node with val -> 3\n- delete node at pos -> 4\n- display list -> 5\n- Quit ->'q'\n");

        scanf(" %c", &choice);
        if (choice == 'q') {
            quit_list();
            break;
        }
        switch(choice) {
        case '1':
            create_list();
            print_list();
            break;

        case '2':
            printf("Before addition\n");
            print_list();
            add_node();
            printf("After addition\n");
            print_list();
            break;


        case '3':
            printf("Before deletion\n");
            print_list();
            del_data();
            printf("After deletion\n");
            print_list();
            break;

        case '4':
            printf("Before deletion\n");
            print_list();
            del_pos();
            printf("After deletion\n");
            print_list();
            break;

        case '5':
            print_list();
            break;

        default:
            printf("Wrong choice option %c. Re-enter list operation choices\n", choice);
            break;
        }

    }

    return 0;
}
