/*
Stack - LIFO - Items are pushed on (Last In is the First Out) and pushed out
*/

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

//Preprocessor Directive: Defining magic numbers as macros
#define STACK_LENGTH 5 //depth of stack, predefined
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN 

typedef struct {
    int defstack[STACK_LENGTH]; //stack needs array
    int top; //and top, IN C, NO OBJECTS SO CANT DEFINE IN CONSTRUCTOR
} stack; //idea is to hold the base DS as an ADT

//Stack implementation as array
//int mystack[STACK_LENGTH];
//int top = EMPTY; //Pushed one item makes top 0

bool push(stack *mystack, int value) {
    if (mystack->top >= STACK_LENGTH-1) return false;

    mystack->top++;
    mystack->defstack[mystack->top] = value;
    return true;
}

int pop(stack *mystack){
    if (mystack->top == EMPTY) return STACK_EMPTY;
    //error message could be anything, a struct with error message, INT_MIN == -2147483648, here i choose -1 as stack shouldnt have negative
    int result = mystack->defstack[mystack->top];
    mystack->top--;
    return result;
}

int main(){
    stack s1;
    s1.top = EMPTY;
    stack s2;
    s2.top = EMPTY;
    stack s3;
    s3.top = EMPTY;
    push(&s1, 56); //address of stack to add value
    push(&s2, 78);
    push(&s3, 13);
    push(&s1, 1);

    int t;
    while ((t = pop(&s1)) != STACK_EMPTY){
        printf("t = %d\n",t);
    }

}