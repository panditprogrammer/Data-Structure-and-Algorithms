#include <stdio.h>


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

//preorder traversal in linked binary tree (root first)
void preorder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//postorder traversal in linked binary tree (root end)
void postorder(struct Node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

//In order traversal in linked binary tree (root in between)
void Inorder(struct Node *root)
{
    if(root != NULL)
    {
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}


int main()
{
    system("cls");

    // create root node
    struct Node *root = CreateNode(50);

    // create child node
    struct Node *n1 = CreateNode(10);
    struct Node *n2 = CreateNode(40);

    // linked nodes
    root->left = n1;
    root->right = n2;

    // pre order traversal
    preorder(root);
    printf("\n");

    //post order traversal
    postorder(root);
    printf("\n");

    //In order traversal
    Inorder(root);

    printf("\n");
    system("pause");
}
