/*

#include "binarytree.hpp"
#include <cmath>
#include <stack>

BinaryTree::BinaryTree()
{
    root = nullptr;
}

void BinaryTree::AddNode(Node *newNode, Node *parentNode, char LR)
{
    if(LR = 'R')
    {
        parentNode->right = newNode;
    }
    else if(LR = 'L')
    {
        parentNode->left = newNode;
    }
    else
    {
        //throw std::invalid_argument("[ERROR] : arg : LR must be a char R or L");
    }
}


void BinaryTree::DeleteNode(Node *node)
{
    delete node;
}

int BinaryTree::size(Node *u) 
{
    if (u == NULL) 
    {
        return 0;
    }

    return 1 + size(u->left) + size(u->right);
}

int BinaryTree::height(Node *u) 
{
    if (u == NULL) 
    {
        return -1;
    }
    return 1 + std::max(height(u->left), height(u->right));
}


*/