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

int main ()
{
    printf("Hello World \n");
    
    testCode_Stack();
    
    testCode_Queue();
    
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



