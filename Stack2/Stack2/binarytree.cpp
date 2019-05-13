//
//  binarytree.cpp
//  
//
//  Created by venkata bethamcharla on 5/6/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "binarytree.hpp"
#include "utilities.h"
#include "stack.hpp"
//#include "Queue.hpp"
#include <iostream>
#include <queue>
#include <stack>


treeNode * createTree()
{
    treeNode * root = (treeNode *)malloc(sizeof(treeNode));
    root->data = 1;
    root->left = NULL;
    root->right = NULL;
    
    root->left = (treeNode *)malloc(sizeof(treeNode));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (treeNode *)malloc(sizeof(treeNode));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;
    
    
    root->left->left = (treeNode *)malloc(sizeof(treeNode));
    root->left->left->data = 4;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    
    root->left->right = (treeNode *)malloc(sizeof(treeNode));
    root->left->right->data = 5;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    
    root->right->left = (treeNode *)malloc(sizeof(treeNode));
    root->right->left->data = 6;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    
    root->right->right = (treeNode *)malloc(sizeof(treeNode));
    root->right->right->data = 7;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    
    return root;
}

void preOrder(treeNode * root)
{
    if (root)
    {
        dprint(tree data, root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void deleteTree(treeNode *root)
{
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    //  Delete current node only after deleting subtrees
    free(root);
    root = NULL;
    return;
#if 0
    treeNode * root = (treeNode *)malloc(sizeof(treeNode));
    root->data = 1;
    root->left = NULL;
    root->right = NULL;
    
    root->left = (treeNode *)malloc(sizeof(treeNode));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (treeNode *)malloc(sizeof(treeNode));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;
    
    
    root->left->left = (treeNode *)malloc(sizeof(treeNode));
    root->left->left->data = 4;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    
    root->left->right = (treeNode *)malloc(sizeof(treeNode));
    root->left->right->data = 5;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    
    root->right->left = (treeNode *)malloc(sizeof(treeNode));
    root->right->left->data = 6;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    
    root->right->right = (treeNode *)malloc(sizeof(treeNode));
    root->right->right->data = 7;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    
    return root;

#endif
}

void preOrderNonRecursiveTraversal(treeNode *root)
{
    Stack_t *s;
    s = stackNew(sizeof(treeNode));
    
    while (1)
    {
        while (root)
        {
            printf ("%d\t",root->data);
            push(s, &root);
            root = root->left;
        }
        
        if(isStackEmpty(s))
            break;
        pop(s, &root);
        root = root->right;
    }
    stackDispose(s);
    
    printf ("\n");
}

void inOrder(treeNode * root)
{
    if (root)
    {
        inOrder(root->left);
        printf("%d\t",root->data);
        inOrder(root->right);
    }
    return;
}

void inOrderNonRecursiveTraversal(treeNode *root)
{
    Stack_t *s = stackNew(sizeof(treeNode));
    
    while (1) {
        
        while (root) {
            push(s, &root);
            root = root->left;
        }
        if(isStackEmpty(s))
            break;
        pop(s, &root);
        printf("%d\t",root->data);
        root = root->right;
    }
    
    stackDispose(s);
    
    printf("\n");
}

void postOrder(treeNode * root)
{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\t",root->data);
    }
    return;
}

void postOrderNonRecursiveTraversal(treeNode *root)
{
    Stack_t *s = stackNew(sizeof(treeNode));
    treeNode *previous = NULL;
    do {
        while (root) {
            push(s, &root);
            root = root->left;
        }
        while (root == NULL && !isStackEmpty(s)) {
            top(s, &root);
            if(root->right == NULL || root->right == previous)
            {
                printf("%d \t", root->data);
                pop(s, &root);
                previous = root;
                root = NULL;
            }
            else
            {
                root = root->right;
            }
        }
    } while(!isStackEmpty(s));
    
    stackDispose(s);
    return;
}

void levelOrderNonRecursiveTraversal(treeNode *root)
{
    if (root == NULL)
        return;

    std::queue<treeNode *> q;
    q.push(root);
    
    while (!q.empty()) {
        root = q.front();
        q.pop();
        printf("%d \t", root->data);
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
    }
    return;
}

// Give an algorithm to find maximum element in binary tree
int findMaxElementBinaryTree(treeNode *root)
{
    assert(root);
    
    std::queue<treeNode *> q;
    int maxElement = MIN_INT32;
    q.push(root);
    
    while (!q.empty()) {
        root = q.front();
        q.pop();
        if (root->data > maxElement)
            maxElement = root->data;
        if (root->left)
            q.push(root->left);
        if (root->right)
            q.push(root->right);
    }
    dprint(max Element, maxElement);
    return maxElement;
    
}

// search for a element in binary tree,
// if found please return 1, orherwsie return 0

int searchElementBinaryTree(treeNode *root, int searchElement)
{
    assert(root);
    
    std::queue<treeNode *> q;
    
    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        if (root->data == searchElement)
            return 1;
        if (root->left)
            q.push(root->left);
        if (root->right)
            q.push(root->right);
    }
    
    return 0;
}

// add an element to existing binary tree
// left node/right node which ever occurs first
treeNode * InsertanElementBinaryTree(treeNode *root, int data)
{
    treeNode *newNode = new treeNode;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    if (root == NULL)
    {
        root = newNode;
        return root;
    }
    treeNode *rootBank = root;
    
    std::queue<treeNode *> q;
    
    q.push(root);
    
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        
        if (root->left)
        {
            q.push(root->left);
        }
        else
        {
            root->left = newNode;
            break;
        }
        
        if (root->right)
        {
            q.push(root->right);
        }
        else
        {
            root->right = newNode;
            break;
        }
    }
    
    return rootBank;
}

// find the size of binary tree by recursion
int findSizeOfBinaryTreeByRecursion(treeNode * root)
{
    if (root == NULL)
        return 0;
    else
        return findSizeOfBinaryTreeByRecursion(root->left) + 1 + findSizeOfBinaryTreeByRecursion(root->right);
}

// find the size of binary tree by non-recursion
int findSizeOfBinaryTreeByNonRecursion(treeNode * root)
{
    if (root == NULL)
        return 0;
    
    std::queue<treeNode *> q;
    int node_count = 0;
    q.push(root);
    
    while (!q.empty()) {
        root = q.front();
        q.pop();
        node_count++;
        if(root->left)  q.push(root->left);
        if(root->right) q.push(root->right);
    }
    
    return node_count;
}


// print the tree elements in reverse order of level ordered traverse
void printLevelOrderedTraversalInReverseOrder(treeNode * root)
{
    if (root == NULL)
        return;
    std::stack<treeNode *> stk;
    std::queue<treeNode *> que;
    
    que.push(root);
    while (!que.empty()) {
        root = que.front();
        que.pop();
        if (root->left) que.push(root->left);
        if (root->right) que.push(root->right);
        stk.push(root);
    }
    
    while (!stk.empty()) {
        printf("%d \t",stk.top()->data);
        stk.pop();
    }
    
    return;
}

// Find the heightOfBinarytree
int HeightOfBinaryTree(treeNode * root)
{
    int leftHeight, rightHeight;
    if (root == NULL)
        return 0;
    else
    {
        leftHeight = HeightOfBinaryTree(root->left);
        rightHeight = HeightOfBinaryTree(root->right);
        if (leftHeight > rightHeight)
        {
            return leftHeight+1;
        }
        else
        {
            return rightHeight+1;
        }
    }
}
// Give an algorithm for height of binary tree
int HeightOfBinaryTreeNoRecursion(treeNode * root)
{
    if (root == NULL)
        return 0;
    
    std::queue<treeNode *> que;
    int level = 0;
    
    que.push(root);
    que.push(NULL); //  indicating one level done
    
    while (!que.empty())
    {
        root = que.front();
        que.pop();
        if (root == NULL)
        {
            level++;
            if(!que.empty())
                que.push(NULL);
        }
        else
        {
            if (root->left)
                que.push(root->left);
            if (root->right)
                que.push(root->right);
        }
    }
    
    return level;
}

// Give an algorithm for finding deepest node of the binary tree
treeNode * findDeepestNodeinBinaryTree(treeNode * root)
{
    if (root == NULL)
        return root;
    
    std::queue<treeNode *> qu;
    treeNode * temp = NULL;
    
    qu.push(root);
    while(!qu.empty())
    {
        temp = qu.front();
        qu.pop();
        if (temp->left)
            qu.push(temp->left);
        if (temp->right)
            qu.push(temp->right);
    }
    
    return temp;
}

// Give an algorithm for finding number of leaves in
// binary tree with out recursion.
int findNumberOfLeafNodesInBinaryTree(treeNode *root)
{
    if (root == NULL)
        return 0;
    std::queue<treeNode *> qu;
    int leaf_node_count = 0;
    std::vector<int> leafNode;
    qu.push(root);
    
    while (!qu.empty()) {
        
        root = qu.front();
        qu.pop();
        
        if ((root->left == NULL)&& (root->right == NULL))
        {
            leaf_node_count++;
            leafNode.push_back(root->data);
        }
        else
        {
            if (root->left)
                qu.push(root->left);
            if (root->right)
                qu.push(root->right);
        }
    }
    
    sprint(\n);
    for (int i=0; i < leafNode.size(); i++)
    {
        printINT(leafNode[i]);
    }
    sprint(\n);
    
    return leaf_node_count;
}
