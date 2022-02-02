#include <stdio.h>
// Binary Search Tree checking

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

// checking binary search tree
int isBST(struct Node *root)
{
    static struct Node *prevNode = NULL; // for previous or left Node
    if(root != NULL)
    {
        if(!isBST(root->left)) // if left Node
            return 0;
        if(prevNode != NULL && root->data <= prevNode->data) //if left Node data less than previ
            return 0;

        prevNode = root; // update prev node
        return isBST(root->right);  //check for right Node
    }
    return 1;
}



int main()
{
    system("cls");

    // create root node
    struct Node *root = CreateNode(50);

    // create child node for BST
    struct Node *n1 = CreateNode(40);
    struct Node *n2 = CreateNode(66);
    struct Node *n3 = CreateNode(34);
    struct Node *n4 = CreateNode(45);

    // linked nodes
    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

//    Inorder(root);

    printf("%d ",isBST(root));

    printf("\n");
    system("pause");
}
