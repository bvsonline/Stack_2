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

// Print the tree elements in reverse order of level ordered traversal
void printLevelOrderedTraversalInReverseOrder(treeNode * root);

// find the height of binary  tree
int HeightOfBinaryTree(treeNode * root);

// find the height of binary tree with no recursion
int HeightOfBinaryTreeNoRecursion(treeNode * root);

// find the deepest node of binary tree with no recursion
treeNode * findDeepestNodeinBinaryTree(treeNode * root);

// find the leaf nodes of binary tree with no recursion
int findNumberOfLeafNodesInBinaryTree(treeNode *root);

// find the full nodes of binary tree with no recursion
int findNumberOfFullNodesInBinaryTree(treeNode *root);

// find the half nodes of binary tree with no recursion
int findNumberOfHalfNodesInBinaryTree(treeNode *root);

// Give an algorithm to find if two binary trees are
// identical structurally.
int determineIfBinaryTreesIdentical(treeNode *tree1, treeNode *tree2);

// Give an algorithm to find if two binary trees are
// identical structurally - Non-recursive
int determineIfBinaryTreesIdenticalNonRecurive(treeNode *tree1, treeNode *tree2);

// Give an algorithm to find level with maximum sum
int FindLevelwithMaxSum(treeNode *root);

// Give an algorithm to find sum of all nodes in binary tree
int findTheSumOfAllNodesInBinaryTree(treeNode *root);

// Give an algorithm to return the mirror of the binary tree
treeNode * MirrorOfTheBinaryTreeRecursion(treeNode *root);

// Give an algorithm to return the mirror of the binary tree iterative way
treeNode * MirrorOfTheBinaryTreeIterative(treeNode *root);

// Give an algorithm to check if two trees are mirrors to each other
int areTreesMirrorImageRecursion(treeNode *a, treeNode *b);

#endif /* binarytree_hpp */
