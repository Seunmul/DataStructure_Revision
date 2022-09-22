// Stack_List.h

#ifndef Stack_List_H
#define Stack_List_H

#define TRUE 1
#define FALSE 0

#include <stdlib.h>
#include <stdio.h>



// header
typedef int Bool;
typedef int Element;

typedef struct tStackNode
{
    Element data;
    struct tStackNode *next;
} StackNode;

typedef struct
{
    int count;
    StackNode *top;
} Stack;

Bool IsFullStack(Stack *pStack);
Bool IsEmptyStack(Stack *pStack);
Stack *CreateStack(int size);
void DestroyStack(Stack *pStack);
void Push(Stack *pStack, Element item);
int Pop(Stack *pStack);
int Top(Stack *pStack);
int CountStackItem(Stack *pStack);
void ClearStack(Stack *pStack);

//.Stack_List.c
// size is not used in linked list implementation
Bool IsFullStack(Stack *pStack)
{
    return FALSE;
}

//���� ������ count�� �����ؼ�, 0�̸��ϰ�� true��ȯ.
Bool IsEmptyStack(Stack *pStack)
{
    if (pStack->count <= 0)
        return TRUE;
    else
        return FALSE;
}

// list�� stack ����, ��ȯ��: Stack* //size is not used in linked list implementation
Stack *CreateStack(int size)
{
    Stack *pStack = (Stack *)malloc(sizeof(Stack)); // Stack ����ü ������ ���� �� �����Ҵ�
    if (pStack == NULL)
    {
        printf("ERROR : Stack is NULL");
        return NULL;
    }
    pStack->count = 0;
    pStack->top = NULL;

    return pStack;
}

// Stack�� �Ҵ�� �޸𸮸� ����
// Stack�� �� ������ ���� ���ó���� ���� �޸𸮸� ������ ��, count�� 0�� �Ǹ� ������ �������� pStack�� �޸𸮸� ����.
void DestroyStack(Stack *pStack)
{
    while (!IsEmptyStack(pStack))
    {
        pStack->top->data = 0;
        StackNode *pOldTop = pStack->top;
        pStack->top = pStack->top->next;
        free(pOldTop);
        pStack->count--;
        // printf("destroy %d\n", pStack->count);
    }
    // printf("destroy %d\n", pStack->count);
    free(pStack);
}

//���� Stack�� ���� ���ó�带 �߰��ϰ� ���� ���ó��� ���� ����(top)�� next����� �ּҸ� ����(���� ���ó�忡 ����)
//���� ������ top�� ���� ���ó�带 �ּҸ� ����
void Push(Stack *pStack, Element item)
{
    StackNode *pNewNode = (StackNode *)malloc(sizeof(StackNode));
    if (pNewNode == NULL)
        return;
    pNewNode->data = item;
    pNewNode->next = pStack->top;
    pStack->top = pNewNode;
    pStack->count++;
}

//���� ������ empty���¸� Ȯ�� ��, item�� �����ϸ� ���� item�� ��ȯ
//��ȯ �� �ش� ���� ���� �޸� ����
Element Pop(Stack *pStack)
{
    if (IsEmptyStack(pStack))
        return 0;
    else
    {
        Element item = pStack->top->data;
        StackNode *pOldTop = pStack->top;
        pStack->top = pStack->top->next;
        free(pOldTop);
        pStack->count--;
        return item;
    }
}

//���� ������ ž ����� �����͸� ��ȯ.
Element Top(Stack *pStack)
{
    if (IsEmptyStack(pStack))
        return 0;
    else
    {
        return pStack->top->data;
    }
}

//���� ������ ����� ��ȯ.
int CountStackItem(Stack *pStack)
{
    return pStack->count;
}

//�ֻ��� ���� ������ �� �ܰ�� �������鼭 ���� �����ϰ� �޸��Ҵ� ����
// count�� 0�϶� ����.
void ClearStack(Stack *pStack)
{
    while (!IsEmptyStack(pStack))
    {
        pStack->top->data = 0;
        StackNode *pOldTop = pStack->top;
        pStack->top = pStack->top->next;
        free(pOldTop);
        pStack->count--;
        // printf("destroy %d\n", pStack->count);
    }
    printf("destroy %d\n", pStack->count);
    return;
}

#endif
