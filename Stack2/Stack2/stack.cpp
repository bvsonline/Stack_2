//
//  stack.cpp
//  Stack2
//
//  Created by venkata bethamcharla on 5/2/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "stack.hpp"

#define INITIAL_STACK_SIZE        64

static void stackGrow(Stack_t *s);

Stack_t * stackNew(int elementSize)
{
    Stack_t *s = (Stack_t *)malloc(sizeof(Stack_t));
    assert(s);
    
    s->logical_length = 0;
    s->allocated_length = INITIAL_STACK_SIZE;
    s->elementSize = elementSize;
    s->sElement = malloc(s->allocated_length*elementSize);
    
    assert(s->sElement);
    
    return s;
}

void stackDispose(Stack_t *s)
{
    free(s->sElement);
    free(s);
}

void push(Stack_t *s, void *elemAddr)
{

    if (s->logical_length == s->allocated_length)
        stackGrow(s);
    
    void *target = (char *)s->sElement + s->logical_length * s->elementSize;
    
    memcpy(target, elemAddr, s->elementSize);
    s->logical_length++;
    
}

void pop(Stack_t *s, void *elemAddr)
{
    //assert(s->logical_length > 0);
    if(isStackEmpty(s))
    {
        return;
    }
    void *source = (char *)s->sElement + (s->logical_length-1) * s->elementSize;
    memcpy(elemAddr, source, s->elementSize);
    s->logical_length--;
    
    return;
}

void top(Stack_t *s, void *elemAddr)
{
    if(isStackEmpty(s))
    {
        return;
    }
    
    void *source = (char *)s->sElement + (s->logical_length-1) * s->elementSize;
    memcpy(elemAddr, source, s->elementSize);
    
    return;
}

static void stackGrow(Stack_t *s)
{
    s->allocated_length *= 2;
    s->sElement = realloc(s->sElement, s->allocated_length*s->elementSize);
    assert(s->sElement != NULL);
    return;
}

int isStackEmpty(Stack_t *s)
{
    return s->logical_length == 0;
}
