/*
stack linkedlist implementation. dynamic so stack length is not needed to be known
*/

#include <stdio.h> //io for printf
#include <limits.h> //int_min
#include <stdbool.h> //bool
#include <stdlib.h> //struct

//macros
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

typedef struct node {
    int value; //current node value
    struct node *next; //points to the next value in the list (node struct)
} node;

typedef node * stack; //init node as pointer to init stack (head of list)
//node* head = NULL; //init node as empty head

bool push(stack *mystack, int value){
    node *newnode = malloc(sizeof(node)); //dynamic as long as memory is sufficient
    if (newnode == NULL) return false;
    //struct assignments
    newnode->value = value;
    newnode->next = *mystack; //added to the front of the list, initially null, when pushed the new head (*mystack) is at the back of the list with the fursthst next being NULL
    *mystack = newnode;
    return true;
}

int pop(stack *mystack){ //passing in as stack ensures direct access and changes persist outside function scope
    if (*mystack == NULL) return STACK_EMPTY;

    int result = (*mystack)->value;
    node *tmp = *mystack; //new temp ndoe to hold the current head (*mystack) node (the last one to be added, thats why when we added nodes we would make it the new node and the next point to previous node, as in the plate analogy as we keep adding plates, the new plates will be the first one out so will be the new head) head popped first, def of head
    *mystack = (*mystack)->next; //next in list
    free(tmp); //garbage collecting
    return result;
}

int main(){
    stack s1 = NULL, s2 = NULL, s3 = NULL;
    push(&s1, 56); //address of stack to add value
    push(&s2, 78);
    push(&s3, 13);
    push(&s1, 1);

    int t;
    while ((t = pop(&s1)) != STACK_EMPTY){
        printf("t = %d\n",t);
    }
}


