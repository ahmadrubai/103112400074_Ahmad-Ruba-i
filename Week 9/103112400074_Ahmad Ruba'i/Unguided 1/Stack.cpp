#include "stack.h"
#include <iostream>

using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == maxElmt - 1;
}

void Push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh" << endl;
    }
}

infotype Pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        return -999;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    if (!isEmpty(S)) {
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        infotype tempArray[maxElmt];
        int count = 0;

        while (!isEmpty(S)) {
            tempArray[count] = Pop(S);
            count++;
        }

        for (int i = 0; i < count; i++) {
            Push(S, tempArray[i]);
        }
    }
}