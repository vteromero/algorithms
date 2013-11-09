// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>
//
// This file tests the BST class

#include <stdio.h>

#include "structure/bst.h"

void PrintValue(const int &value)
{
    printf("%d ", value);
}

void CheckValue(BST<int>& bst, const int& value)
{
    BSTNode<int> *node = bst.Search(value);
    if(node == NULL)
        printf("Value %d doesn't exist!\n", value);
    else
        printf("Value %d exist!\n", value);
}

int main()
{
    BST<int> bst;
    void (*p_funct)(const int&) = PrintValue;

    printf("\n****** Inserting values ******\n");
    bst.Insert(44);
    bst.Insert(4);
    bst.Insert(3);
    bst.Insert(13);
    bst.Insert(-10);
    bst.Insert(-22);
    bst.Insert(9);

    printf("In-order tree walk: ");
    bst.InOrderWalk(p_funct);
    printf("\n");

    printf("Reverse in-order tree walk: ");
    bst.ReverseInOrderWalk(p_funct);
    printf("\n");

    printf("Pre-order tree walk: ");
    bst.PreOrderWalk(p_funct);
    printf("\n");

    printf("Post-order tree walk: ");
    bst.PostOrderWalk(p_funct);
    printf("\n");

    printf("Size: %d\n", bst.size());
    printf("Minimum: %d\n", bst.Minimum());
    printf("Maximum: %d\n", bst.Maximum());

    printf("\n****** Deleting values ******\n");
    bst.Delete(-10);
    bst.Delete(13);
    bst.Delete(44);

    printf("In-order tree walk: ");
    bst.InOrderWalk(p_funct);
    printf("\n");

    printf("Reverse in-order tree walk: ");
    bst.ReverseInOrderWalk(p_funct);
    printf("\n");

    printf("Pre-order tree walk: ");
    bst.PreOrderWalk(p_funct);
    printf("\n");

    printf("Post-order tree walk: ");
    bst.PostOrderWalk(p_funct);
    printf("\n");

    printf("Size: %d\n", bst.size());
    printf("Minimum: %d\n", bst.Minimum());
    printf("Maximum: %d\n", bst.Maximum());

    printf("\n****** Checking values ******\n");
    CheckValue(bst, 1000);
    CheckValue(bst, 3);

    printf("\n****** Accessing through position ******\n");
    printf("Value at 0: %d\n", bst.Get(0));
    printf("Value at 2: %d\n", bst.Get(2));

    return 0;
}
