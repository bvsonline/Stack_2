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

// find maximum elemnt in binary tree
int findMaxElementBinaryTree(treeNode *root);

// search element in binary tree
int searchElementBinaryTree(treeNode *root, int searchElement);

// Insert an element in Binary tree
treeNode * InsertanElementBinaryTree(treeNode *root, int data);

// Find size of Binary tree by recursion
int findSizeOfBinaryTreeByRecursion(treeNode * root);

// Find size of binary tree by non-recursion
int findSizeOfBinaryTreeByNonRecursion(treeNode * root);

#endif /* binarytree_hpp */
