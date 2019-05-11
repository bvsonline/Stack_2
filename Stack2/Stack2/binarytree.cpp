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
