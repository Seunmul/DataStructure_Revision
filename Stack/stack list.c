// stack list.c

#include "stack list.h"
#define STACK_SIZE 30

bool IsFullStack(Stack *pStack);
bool IsEmptyStack(Stack *pStack);
Stack *CreateStack(int size);
void DestroyStack(Stack *pStack);
void Push(Stack *pStack, Element item);
int Pop(Stack *pStack);
int Top(Stack *pStack);
int CountStackItem(Stack *pStack);
void ClearStack(Stack *pStack);

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
