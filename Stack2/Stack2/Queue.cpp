//
//  Queue.cpp
//  Stack2
//
//  Created by venkata bethamcharla on 5/4/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Queue.hpp"

// Queue implementation

Q * createQueue(int elementSize)
{
    Q *queue = (Q *) malloc(sizeof(Q));
    assert(queue);
    queue->read = queue->write = -1;
    queue->capacity = 4;
    queue->elementSize = elementSize;
    queue->QElem = malloc(sizeof(queue->capacity*elementSize));
    assert(queue->QElem);
    return queue;
}

int enQueue(Q *q, void *element)
{
    
    assert(q);
    assert(q->QElem);
    
    if (isQueueFull(q))
    {
#if 0
        printf("Queue Overflow \n");
        return -1;
#endif
        queueGrow(q);
    }
    
    q->write = (q->write+1)%q->capacity;
    void *target = (char *) q->QElem + (q->write * q->elementSize);
    memcpy(target, element, q->elementSize);
    if (q->read == -1)
    {
        q->read = q->write;
    }
    
    return 0;
}

int deQueue(Q *q, void *element)
{
    assert(q);
    assert(q->QElem);
    
    if (isQueueEmpty(q))
    {
        printf("Queue Empty \n");
        return -1;
    }
    
    void * source = (char *) q->QElem + (q->read * q->elementSize);
    memcpy(element, source, q->elementSize);
    if (q->read == q->write)
    {
        q->read = q->write = -1;
    }
    else
    {
        q->read = (q->read + 1 )%q->capacity;
    }
    
    return 0;
    
}
int isQueueEmpty(Q *q)
{
    assert(q);
    return (q->read == -1);
}

int isQueueFull(Q *q)
{
    assert(q);
    return (q->read == (q->write+1)%q->capacity);
}

void deleteQueue(Q *q)
{
    free(q->QElem);
    free(q);
}

int queueGrow(Q *q)
{
    q->capacity *= 2;
    q = (Q *)realloc(q, q->capacity*q->elementSize);
    assert(q);
    return 0;
}
