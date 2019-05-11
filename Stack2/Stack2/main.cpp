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
#include "stack.hpp"
#include "Queue.hpp"
#include "test.hpp"
#include "utilities.h"
#include "binarytree.hpp"

int main ()
{
    printf("Hello World \n");
    
    testCode_Stack();
    
    testCode_Queue();
    
    testCode_p3();
    
    testCode_treePreorderTraversal();
    
    testCode_preOrderNonRecursiveTraversal();
    
    return 0;
}


typedef struct Movie{
    char * name;
    int year;
} movie;

void testCode_Stack(void)
{
    Stack_t *s;
    
    s = stackNew(sizeof(movie));
    
    movie m1, m2, m3, m4, m5;
    
    m1.name = (char *)"MOVIE 1";
    m1.year = 2011;
    
    m2.name = (char *)"MOVIE 2";
    m2.year = 2012;
    
    m3.name = (char *)"MOVIE 3";
    m3.year = 2013;

    m4.name = (char *)"MOVIE 4";
    m4.year = 2014;
    
    m5.name = (char *)"MOVIE 5";
    m5.year = 2015;
    
    push(s, &m1);
    push(s, &m2);
    push(s, &m3);
    push(s, &m4);
    push(s, &m5);
    
    pop(s, &m2);
    pop(s, &m1);
    pop(s, &m1);
    pop(s, &m1);
    pop(s, &m1);
    
    stackDispose(s);
    return;
}



void testCode_Queue(void)
{
    Q *q;
    
    q = createQueue(sizeof(movie));
    
    movie m1, m2, m3, m4, m5;
    
    m1.name = (char *)"MOVIE 1";
    m1.year = 2011;
    
    m2.name = (char *)"MOVIE 2";
    m2.year = 2012;
    
    m3.name = (char *)"MOVIE 3";
    m3.year = 2013;
    
    m4.name = (char *)"MOVIE 4";
    m4.year = 2014;
    
    m5.name = (char *)"MOVIE 5";
    m5.year = 2015;
    
    enQueue(q, &m1);
    enQueue(q, &m2);
    enQueue(q, &m3);
    enQueue(q, &m4);
    enQueue(q, &m5);
    enQueue(q, &m5);
    enQueue(q, &m4);
    enQueue(q, &m3);
    enQueue(q, &m2);
    
    deQueue(q, &m2);
    deQueue(q, &m1);
    deQueue(q, &m1);
    deQueue(q, &m1);
    deQueue(q, &m1);
    
    deleteQueue(q);
    
    return;
}


void testCode_p3(void)
{
    Stack_t *S = stackNew(sizeof(int));
    
    int data_to_push[11] = {2,3,4,5,6,7,8,9,10,11, 14};
    
    push(S, &data_to_push[0]);
    push(S, &data_to_push[1]);
    push(S, &data_to_push[2]);
    push(S, &data_to_push[3]);
    push(S, &data_to_push[4]);
    push(S, &data_to_push[5]);
    push(S, &data_to_push[6]);
    push(S, &data_to_push[7]);
    push(S, &data_to_push[8]);
    push(S, &data_to_push[9]);
    push(S, &data_to_push[10]);
    
    if(CheckStackPairwiseOrder(S))
    {
        printf("contents are pairwise ordered \n");
    }
    else
    {
        printf("contents are not pairwise ordered \n");
    }
    
    return;
}


int CheckStackPairwiseOrder(Stack_t *S)
{
    Q *q;
    int element, m, n, pair_wise_order = 1;
    
    q = createQueue(sizeof(int));
    
    while (!isStackEmpty(S))
    {
        pop(S, &element);
        enQueue(q, &element);
    }
    
    while (!isQueueEmpty(q))
    {
        deQueue(q, &element);
        push(S, &element);
    }
    
    while (!isStackEmpty(S)) {
        
        pop(S, &m);
        enQueue(q, &m);
        
        if (!isStackEmpty(S))
        {
            pop(S, &n);
            enQueue(q, &n);
            if (abs(m-n) == 1)
                pair_wise_order *= 1;
            else
                pair_wise_order *= 0;
        }
    }

    while(!isQueueEmpty(q))
    {
        deQueue(q, &element);
        push(S, &element);
    }
    
    deleteQueue(q);
    
    return pair_wise_order;
}

void testCode_treePreorderTraversal()
{
    treeNode * tree = createTree();
    preOrder(tree);
    deleteTree(tree);
    return;
}


void testCode_preOrderNonRecursiveTraversal()
{
    treeNode * tree = createTree();
    preOrderNonRecursiveTraversal(tree);
    deleteTree(tree);
    return;
}

