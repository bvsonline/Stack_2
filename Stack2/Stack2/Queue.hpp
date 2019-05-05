//
//  Queue.hpp
//  Stack2
//
//  Created by venkata bethamcharla on 5/4/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>

#define SUCCESS (0)
#define FAILURE (-1)

typedef struct Queue{
  
    int read;
    int write;
    int capacity;
    int elementSize;
    void *QElem;
}Q;



Q * createQueue(int elementSize);
int enQueue(Q *q, void *element);
int deQueue(Q *q, void *element);
int isQueueEmpty(Q *q);
int isQueueFull(Q *q);
void deleteQueue(Q *q);
int queueGrow(Q *q);

void testCode_Queue(void);


typedef struct ListNode{
    int data;
    struct ListNode *next;
}List;

typedef struct QueueLL{
    List *write;
    List *read;
} Q_ll;

Q_ll * createQueue_ll();
void enQueue_ll(Q_ll *q, int data);
void deQueue_ll(Q_ll *q, int *data);
int isQueueEmpty_ll(Q_ll *q);
void deleteQueue_ll(Q_ll *q);



#endif /* Queue_hpp */
