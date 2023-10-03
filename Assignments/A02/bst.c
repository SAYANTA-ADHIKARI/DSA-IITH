#include <stdio.h>

typedef struct BSTNode
{
    int data;
    int height;
    struct BSTNode *left;
    struct BSTNode *right;
    struct BSTNode *parent;
} BSTNode;

int height(BSTNode *root)
{
    if (root == NULL)
        return -1;
    else
        return root->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

BSTNode *createNode(int data)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->data = data;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

BSTNode *insert(BSTNode *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
        root->left->parent = root;
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
        root->right->parent = root;
    }
    else
        return root; // Duplicate values are not allowed

    root->height = 1 + max(height(root->left), height(root->right));

    return root;
}

BSTNode *search(BSTNode *root, int data)
{
    if (root == NULL)
        return NULL;
    else if (root->data == data)
        return root;
    else if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

BSTNode *findMin(BSTNode *root)
{
    if (root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    else
        return findMin(root->left);
}

BSTNode *findMax(BSTNode *root)
{
    if (root == NULL)
        return NULL;
    else if (root->right == NULL)
        return root;
    else
        return findMax(root->right);
}

BSTNode *findSuccessor(BSTNode *root)
{
    if (root == NULL)
        return NULL;
    else if (root->right != NULL)
        return findMin(root->right);
    else
    {
        BSTNode *successor = root->parent;
        BSTNode *current = root;
        while (successor != NULL && current == successor->right)
        {
            current = successor;
            successor = successor->parent;
        }
        return successor;
    }
}

BSTNode *findPredecessor(BSTNode *root)
{
    if (root == NULL)
        return NULL;
    else if (root->left != NULL)
        return findMax(root->left);
    else
    {
        BSTNode *predecessor = root->parent;
        BSTNode *current = root;
        while (predecessor != NULL && current == predecessor->left)
        {
            current = predecessor;
            predecessor = predecessor->parent;
        }
        return predecessor;
    }
}

BSTNode *deleteNode(BSTNode *root, int data)
{
    if (root == NULL)
        return NULL;
    else if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            BSTNode *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            BSTNode *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            BSTNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    return root;
}

void printInorder(BSTNode *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d\t", root->data);
    printInorder(root->right);
}

void printPreorder(BSTNode *root)
{
    if (root == NULL)
        return;
    printf("%d\t", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(BSTNode *root)
{
    if (root == NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d\t", root->data);
}
