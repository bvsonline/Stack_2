//
//  binarytree.hpp
//  
//
//  Created by venkata bethamcharla on 5/6/19.
//

#ifndef binarytree_hpp
#define binarytree_hpp

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    TreeNode * left;
    TreeNode * right;
} treeNode;

treeNode * createTree(void);
void preOrder(treeNode * root);
void deleteTree(treeNode *root);

#endif /* binarytree_hpp */
