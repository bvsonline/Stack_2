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
void deleteTree(treeNode *root);

// preOrder
void preOrder(treeNode * root);
void preOrderNonRecursiveTraversal(treeNode *root);

// InOrder
void inOrder(treeNode * root);
void inOrderNonRecursiveTraversal(treeNode *root);

// postOrder
void postOrder(treeNode * root);
void postOrderNonRecursiveTraversal(treeNode *root);

// levelOrder
void levelOrderNonRecursiveTraversal(treeNode *root);

#endif /* binarytree_hpp */
