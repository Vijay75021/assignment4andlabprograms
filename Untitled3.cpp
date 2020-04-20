#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack {
    int v1;
    struct Stack *next;
};


struct Stack *CreateStack () {
    return NULL;
}

int isEmptyStack(struct Stack *top) {
    return (top == NULL);
}

void Push(struct Stack **top, int v1) {
    struct Stack *newNode = (struct Stack*) malloc(sizeof(struct Stack));
    if(!newNode)
        return;
    newNode->v1 = v1;
    newNode->next = *top;
    *top = newNode;
}

int Pop(struct Stack **top) {
    struct Stack *t;
    int v1;

    if(isEmptyStack(*top)) {
        printf("Empty Stack.\n");
        return INT_MIN;
    }

    t = *top;
    v1 = (*top)->v1;
    *top = (*top)->next;
    free(t);
    return v1;
}

struct Queue {
    struct Stack *S1;
    struct Stack *S2;
};

struct Queue *CreateQueue() {

    struct  Queue  *newNode = (struct Queue *) malloc(sizeof(struct  Queue ));

    return newNode;
}

void EnQueue(struct Queue *Q, int v1) {
    Push(&Q->S1, v1);
}

int DeQueue(struct Queue *Q) {
    if(!isEmptyStack(Q->S2)) {
        return Pop(&Q->S2);
    }
    else {
        while(!isEmptyStack(Q->S1)) {
            Push(&Q->S2, Pop(&Q->S1));
        }
        return Pop(&Q->S2);
    }
}

int main() {
    struct Queue *Q = CreateQueue();
    Q->S1 = Q->S2 = NULL;
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 7);

    printf("%v1 ", DeQueue(Q));
    printf("%v1 ", DeQueue(Q));
    printf("%v1 ", DeQueue(Q));

    return 0;
}
