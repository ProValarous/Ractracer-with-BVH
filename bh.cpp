
/*
#include "bh.hpp"



BVH::BVH()
{

}

void BVH::partition(BoundingBox *u, Node *n)
{
    //add condition for base case...
    
    float xLen = u->x_upper - u->x_lower;
    float yLen = u->y_upper - u->y_lower;
    float zLen = u->z_upper - u->z_lower;

    float midpoint;
    Node *currentNode = n;
    BoundingBox *left;
    BoundingBox *right;


    if (xLen > yLen && xLen > zLen)
    {
        midpoint = u->x_lower + (xLen/2);
        left->x_lower = u->x_lower;
        left->x_upper = midpoint;
        left->y_lower = u->y_lower;
        left->y_upper = u->y_upper;
        left->z_lower = u->z_lower;
        left->z_upper = u->z_upper;

        right->x_upper = u->x_upper;
        right->x_lower = midpoint;
        right->y_lower = u->y_lower;
        right->y_upper = u->y_upper;
        right->z_lower = u->z_lower;
        right->z_upper = u->z_upper;


    }
    else if (yLen > xLen && yLen > zLen)
    {
        midpoint = u->y_lower + (yLen/2);
        left->y_lower = u->y_lower;
        left->y_upper = midpoint;
        left->x_lower = u->x_lower;
        left->x_upper = u->x_upper;
        left->z_lower = u->z_lower;
        left->z_upper = u->z_upper;

        right->y_upper = u->y_upper;
        right->y_lower = midpoint;
        right->x_lower = u->x_lower;
        right->x_upper = u->x_upper;
        right->z_lower = u->z_lower;
        right->z_upper = u->z_upper;
    }
    else if (zLen > xLen && zLen > yLen)
    {
        midpoint = u->z_lower + (zLen/2);
        left->z_lower = u->z_lower;
        left->z_upper = midpoint;
        left->x_lower = u->x_lower;
        left->x_upper = u->x_upper;
        left->y_lower = u->y_lower;
        left->y_upper = u->y_upper;


        right->z_upper = u->z_upper;
        right->z_lower = midpoint;
        right->x_lower = u->x_lower;
        right->x_upper = u->x_upper;
        right->y_lower = u->y_lower;
        right->y_upper = u->y_upper;
    }

    Node *leftNode;
    Node *rightNode;

    leftNode->box = left;

    //BT.AddNode(leftNode,currentNode,'L'); //fixx it later
    //BT.AddNode(rightNode,currentNode,'R'); //fixx it later
    

    partition(left,leftNode);
    partition(right,rightNode);

}
*/