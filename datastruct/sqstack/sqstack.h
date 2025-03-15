#ifndef SQSTACK_H_
#define SQSTACK_H_
const int MAXSIZE = 100;
typedef int SQElemType;

// define the SQStack structure
typedef struct
{
    /* data */
    SQElemType *base;
    SQElemType *top;
    int sqstacklength;
} SqStack;

bool InitStack(SqStack &S);  // Initialize a SqStack;
bool StackEmpty(SqStack &S); // confirm whether SqStack is empty;
int getLength(SqStack &S);   // get the length of SqStack
bool ClearStack(SqStack &S); // clear SqStack;
bool DestroyStack(SqStack &S); //destroy the SqStack;
bool pull(SqStack &S, SQElemType e); // pull the SqStack;
bool pop(SqStack &S, SQElemType &e);
#endif