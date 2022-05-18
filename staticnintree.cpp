#include<vector>
#include "sphere.hpp"

using namespace std;

struct BoundingBox
{
    //vector<double> x_lower {0.7, 0.7, 0.7};
    
    float x_lower;
    float x_upper;
    float y_lower;
    float y_upper;
    float z_lower;
    float z_upper;
};

struct Node
{
    Node *left;
    Node *right;
    BoundingBox *box;
    bool isLeaf = true;
};


class BinaryTree
{

    private:

  
    

    public:
        Node *rootNode;
        Node *aNode;
        Node *bNode;
        Node *cNode;
        Node *dNode;

        BinaryTree()
        {
            rootNode->left = aNode;
            rootNode->right = bNode;
            aNode->left = cNode;
            aNode->right = dNode;
        
        }
};


class BVH
{
    private:
        BoundingBox *rootBox;
        BoundingBox *aBox;
        BoundingBox *bBox;
        BoundingBox *cBox;
        BoundingBox *dBox;


    public:

    BinaryTree BT;

    BVH()
    {
        //rootBox
        rootBox->x_lower = 0;
        rootBox->x_upper = 1024;
        rootBox->y_lower = 576;
        rootBox->y_upper = 576;

        //aBox
        aBox->x_lower = 0;
        aBox->x_upper = 682;
        aBox->y_lower = 100;
        aBox->y_upper = 500;

        //bBox
        bBox->x_lower = 683;
        bBox->x_upper = 1024;
        bBox->y_lower = 100;
        bBox->y_upper = 500;

        //cBox
        aBox->x_lower = 20;
        aBox->x_upper = 340;
        aBox->y_lower = 125;
        aBox->y_upper = 475;

        //cBox
        aBox->x_lower = 345;
        aBox->x_upper = 1000;
        aBox->y_lower = 125;
        aBox->y_upper = 475;

        
        
        BT.rootNode->box = rootBox;
        BT.aNode->box = aBox;
        BT.bNode->box = bBox;
        BT.cNode->box = cBox;
        BT.dNode->box = dBox;
        
    }

};



struct node
{
    node *left;
    node *right;
    BoundingSphere *sphere;
    bool isLeaf = true;
};

class BoundingVolHeirachy
{

    public:

    // BinaryTree BT;
    node *root;

    BoundingVolHeirachy()
    {
        node a;
        dsRT::Sphere a1;
        dsRT::Transform Mat1;
        Mat1.SetTransform(qbVector<double>{std::vector<double>{-1.5, 0.0, 0.0}},
					        qbVector<double>{std::vector<double>{0.0, 0.0, 0.0}},
					        qbVector<double>{std::vector<double>{1.0, 1.0, 1.0}});
        a1.SetTransformMatrix(Mat1);
        // a.sphere->inside.push_back(a1);

        node b;
        dsRT::Sphere b1;
        dsRT::Transform Mat2;
        Mat2.SetTransform(qbVector<double>{std::vector<double>{0.0, 0.0, 0.0}},
					        qbVector<double>{std::vector<double>{0.0, 0.0, 0.0}},
					        qbVector<double>{std::vector<double>{1.0, 1.0, 1.0}});
        b1.SetTransformMatrix(Mat2);


        node c;
        dsRT::Sphere c1;
        dsRT::Transform Mat3;
        Mat2.SetTransform(qbVector<double>{std::vector<double>{1.5, 0.0, 0.0}},
					        qbVector<double>{std::vector<double>{0.0, 0.0, 0.0}},
					        qbVector<double>{std::vector<double>{1.0, 1.0, 1.0}});
        c1.SetTransformMatrix(Mat3);


        
    }

};


struct BoundingSphere
{   
    dsRT::Sphere vol;
    std::vector<std::shared_ptr<dsRT::Object>> inside;
};


