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

#endif /* Queue_hpp */
