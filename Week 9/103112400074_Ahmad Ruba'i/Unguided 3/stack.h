#ifndef STACK_H
#define STACK_H

#define maxElmt 20

typedef char infotype;

struct Stack {
    infotype info[maxElmt];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void Push(Stack &S, infotype x);
infotype Pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void getInputStream(Stack &S);

#endif 