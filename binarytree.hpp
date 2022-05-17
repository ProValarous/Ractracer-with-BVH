#include <SDL.h>
#include "AABB.hpp"

struct Node{
    Node *left;
    Node *right;
    aabb::AABB AABBdata;
    bool isLeaf = true;
};

class BinaryTree
{
    private:
        Node *root;
    
    public:

        BinaryTree();

        void AddNode(Node *newNode, char LR);

        void DeleteNode(Node *node);

        int size(Node *u);

        int height(Node *u);




};
