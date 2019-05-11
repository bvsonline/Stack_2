//
//  stack.hpp
//  Stack2
//
//  Created by venkata bethamcharla on 5/2/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

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

Stack_t * stackNew(int elementSize);
void stackDispose(Stack_t *s);
void push(Stack_t *s, void *elemAddr);
void pop(Stack_t *s, void *elemAddr);
void top(Stack_t *s, void *elemAddr);
int isStackEmpty(Stack_t *s);



#endif /* stack_hpp */
