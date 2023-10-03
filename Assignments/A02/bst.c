#include <stdio.h>

typedef struct BSTNode
{
    int data;
    int height;
    struct BSTNode *left;
    struct BSTNode *right;
    struct BSTNode *parent;
} BSTNode;

BSTNode *createNode(int data)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->data = data;
    newNode->height = 0;
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

BSTNode *findSuccessor(BSTNode *root, int data)
{
    BSTNode *current = search(root, data);
    if (current == NULL)
        return NULL;
    else if (current->right != NULL)
        return findMin(current->right);
    else
    {
        BSTNode *successor = NULL;
        BSTNode *ancestor = root;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}

BSTNode *findPredecessor(BSTNode *root, int data)
{
    BSTNode *current = search(root, data);
    if (current == NULL)
        return NULL;
    else if (current->left != NULL)
        return findMax(current->left);
    else
    {
        BSTNode *predecessor = NULL;
        BSTNode *ancestor = root;
        while (ancestor != current)
        {
            if (current->data > ancestor->data)
            {
                predecessor = ancestor;
                ancestor = ancestor->right;
            }
            else
                ancestor = ancestor->left;
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
    return root;
}