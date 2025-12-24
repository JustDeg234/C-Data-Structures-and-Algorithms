/*
queue FIFO - linkedlist implementation
*/

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_EMPTY INT_MIN
//in c, we cant define values in cosntructors
typedef struct node {
    int value;
    struct node *next; //each node contains a child ADT node, this value points to it
} node; //each note in a queue

typedef struct {
    node *head;
    node *tail;
} queue; //in queue, we need to know head and tail (doubly linked list), in stack we only need to know head 

void init_queue(queue *q) { //in OOP languages, would be inside constructor, instead function defining queue
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue *q, int value){
    node * newnode = malloc(sizeof(node)); //new node in memory
    if (newnode == NULL) return false;
    newnode->value = value;
    newnode->next = NULL; //in stack,  head would be at front of list for new items pushed (to be popped first), here in queue its added to the back of the list (points to null)
    if (q->tail != NULL){ //if a tail is populated with a value in the queue, find it and make new node the next value (last of list, so that items are popped first in, then first out)
        q->tail->next = newnode;
    }
    q->tail = newnode;
    if (q->head == NULL){
        q->head = newnode; //just in case there is no head as well. 
    }
    return true;
}

int dequeue(queue *q){
    if (q->head == NULL) return QUEUE_EMPTY;
    node *tmp = q->head; //save the head of the queue
    int result = tmp->value; //we only want value of linked list (value in list/queue)
    q->head = q->head->next; //truncate list by removing current head with next in list. recall head is at back of list pointing to null (furtherst to right if arrows [head->tail])
    if (q->head == NULL){
        q->tail = NULL;
    }
    free(tmp); //avoids memory leak
    return result;
}

int main(){
    queue q1, q2, q3;

    init_queue(&q1);
    init_queue(&q2);
    init_queue(&q3);

    enqueue(&q1, 56);
    enqueue(&q2, 78);
    enqueue(&q3, 23);
    enqueue(&q1, 1);

    int t;
    while((t = dequeue(&q1)) != QUEUE_EMPTY){
        printf("t = %d\n", t);
    }
}