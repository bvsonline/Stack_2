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
#define INITIAL_QUEUE_SIZE  64
Q * createQueue(int elementSize)
{
#if 1
    Q *queue = (Q *) malloc(sizeof(Q));
    assert(queue);
    queue->read = queue->write = -1;
    queue->capacity = INITIAL_QUEUE_SIZE;
    queue->elementSize = elementSize;
    queue->QElem = malloc(sizeof(queue->capacity*elementSize));
    assert(queue->QElem);
    return queue;
#else
    Q queue;    // = (Q *) malloc(sizeof(Q));
    //assert(queue);
    queue.read = queue.write = -1;
    queue.capacity = INITIAL_QUEUE_SIZE;
    queue.elementSize = elementSize;
    queue.QElem = malloc(sizeof(queue.capacity*elementSize));
    assert(queue.QElem);
    return &queue;
#endif
}

int enQueue(Q *q, void *element)
{
    
    assert(q);
    assert(q->QElem);
    
    if (isQueueFull(q))
    {
#if 1
        printf("Queue Overflow \n");
        return -1;
#else
        queueGrow(q);
#endif
    }
    
    q->write = (q->write+1)%q->capacity;
    char *target = (char *) q->QElem + (q->write * q->elementSize);
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
    q->QElem = NULL;
    free(q);
    q = NULL;
    return;
}

void queueGrow(Q *q)
{
    void * temp = NULL;
    q->capacity *= 2;
    temp = (void *)realloc(q->QElem, q->capacity*q->elementSize);
    if (temp == NULL)
    {
        printf("realloc failed \n");
    }
    else
    {
        temp = q->QElem;
    }
    assert(q->QElem);
    return;
}


/********************
 Queue implementation with Linked List
 ********************/
Q_ll * createQueue_ll()
{
    Q_ll *q = (Q_ll *)malloc(sizeof(Q_ll));
    assert(q);
    
    q->read = q->write = NULL;
    
    return q;
}

void enQueue_ll(Q_ll *q, int data)
{
    List *list = (List *)malloc(sizeof(List));
    assert(list);

    list->data = data;
    list->next = NULL;
    
    if (q->write)
        q->write->next = list;
    
    q->write = list;
    
    if (q->read == NULL)
        q->read = q->write;
    
    return;
}

void deQueue_ll(Q_ll *q, int *data)
{
    if (isQueueEmpty_ll(q))
    {
        return;
    }

    *data = q->read->data;
    List * temp = q->read;
    if (q->read->next == NULL)
    {
        // Queue empty
        q->read = q->write = NULL;
    }
    else
    {
        q->read = q->read->next;
    }
    free(temp);
    
    return;
}

int isQueueEmpty_ll(Q_ll *q)
{
    return q->read == NULL;
}

void deleteQueue_ll(Q_ll *q)
{
    free(q);
}
