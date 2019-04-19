//
//  main.cpp
//  StackImplementation
//
//  Created by venkata bethamcharla on 4/18/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct Stack{
    
    void *sElement;
    int logical_length;
    int allocated_length;
    int elementSize;
    
}Stack_t;

void stackNew(Stack_t *s, int elementSize);
static void stackGrow(Stack_t *s);
void stackDispose(Stack_t *s);
void stackPush(Stack_t *s, void *elemAddr);
void stackPop(Stack_t *s, void *elemAddr);


int main ()
{
    printf("Hello World \n");
    
    Stack_t stack;
    int element_size = 4;
    int element;
    
    stackNew(&stack, element_size);
    
    //  push elements 10, 200, 5008, 548900, 45567
    element = 10;
    stackPush(&stack, &element);
    
    element = 200;
    stackPush(&stack, &element);
    
    element = 5008;
    stackPush(&stack, &element);
    
    element = 548900;
    stackPush(&stack, &element);
    
    element = 45567;
    stackPush(&stack, &element);
    
    element = 9887669;
    stackPush(&stack, &element);
    
    //  pop elements
    
    stackPop(&stack, &element);
    printf("Popped Element: %d \n", element);
    
    stackPop(&stack, &element);
    printf("Popped Element: %d \n", element);
    
    stackPop(&stack, &element);
    printf("Popped Element: %d \n", element);
    
    stackPop(&stack, &element);
    printf("Popped Element: %d \n", element);
    
    stackPop(&stack, &element);
    printf("Popped Element: %d \n", element);
    
    stackPop(&stack, &element);
    printf("Popped Element: %d \n", element);
    
    
    stackDispose(&stack);
    
    return 0;
}

void stackNew(Stack_t *s, int elementSize)
{
    s->logical_length = 0;
    s->allocated_length = 4;
    s->elementSize = elementSize;
    s->sElement = malloc(s->allocated_length*elementSize);
    
    assert(s->sElement != NULL);
    
    return;
}

void stackDispose(Stack_t *s)
{
    free(s->sElement);
}

void stackPush(Stack_t *s, void *elemAddr)
{
    if (s->allocated_length == 0)
        stackNew(s, s->elementSize);
    
    if (s->logical_length == s->allocated_length)
        stackGrow(s);
    
    void *target = (char *)s->sElement + s->logical_length * s->elementSize;
    
    memcpy(target, elemAddr, s->elementSize);
    s->logical_length++;
    
}

void stackPop(Stack_t *s, void *elemAddr)
{
    assert(s->logical_length > 0);
    void *source = (char *)s->sElement + (s->logical_length-1) * s->elementSize;
    memcpy(elemAddr, source, s->elementSize);
    s->logical_length--;
    
    return;
}

static void stackGrow(Stack_t *s)
{
    s->allocated_length *= 2;
    s->sElement = realloc(s->sElement, s->allocated_length*s->elementSize);
    assert(s->sElement != NULL);
    return;
}
