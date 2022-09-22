// stack list.c

#include "stack list.h"
#define STACK_SIZE 30

int main()
{
    Stack *pStack = CreateStack(STACK_SIZE);
    for (size_t i = 0; i < 10; i++)
    {
        Push(pStack, i);
        // printf("%d\n",Top(pStack));
    }
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d\n", Pop(pStack));
    }
    DestroyStack(pStack);

    return 0;
}
