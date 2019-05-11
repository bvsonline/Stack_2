//
//  test.h
//  Stack2
//
//  Created by venkata bethamcharla on 5/5/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//

#ifndef test_hpp
#define test_hpp

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "stack.hpp"
#include "Queue.hpp"

void testCode_Queue(void);
void testCode_Stack(void);
void testCode_p3(void);
int CheckStackPairwiseOrder(Stack_t *S);
void testCode_treePreorderTraversal(void);
void testCode_preOrderNonRecursiveTraversal(void);

void testCode_inOrder(void);
void testCode_inOrderNonRecursiveTraversal(void);

void testCode_postOrder(void);
void testCode_postOrderNonRecursiveTraversal(void);

void testCode_levelOrderTraversal(void);

void testCode_findMaxElementBinaryTree(void);

void testCode_searchElementBinaryTree(void);

void testCode_insertElementBinaryTree(void);

void testCode_findSizeOfBinaryTree(void);

void testCode_printReverseOrderOfLevelOrderTraversal(void);

void testCode_findHeightOfBinaryTree(void);

#endif /* test_hpp */
