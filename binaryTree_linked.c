#include <stdio.h>
//Linked Binary tree

//Node structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

//Create node
struct Node* CreateNode(int d)
{
    struct Node *node;
    node = (struct Node*) malloc(sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    node->data = d;
    return node;
}

main()
{
    int arr[] = {12,8,98,34,77};
//    create root node
    struct Node *root = CreateNode(50);

//    create chile node
    struct Node *n1 = CreateNode(10);
    struct Node *n2 = CreateNode(40);

//    linked nodes
    root->left = n1;
    root->right = n2;

    printf("%d",root->data);
}
