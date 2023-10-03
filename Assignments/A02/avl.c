#include <stdio.h>

typedef struct AVLNode
{
    int data;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
    struct AVLNode *parent;
} AVLNode;

int height(AVLNode *node)
{
    if (node == NULL)
        return -1;
    return node->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBalance(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

void updateHeight(AVLNode *node)
{
    if (node == NULL)
        return;
    node->height = 1 + max(height(node->left), height(node->right));
}

AVLNode *leftRotate(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    if (T2 != NULL)
        T2->parent = x;

    x->parent = y;

    updateHeight(x);
    updateHeight(y);

    return y;
}

AVLNode *rightRotate(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    if (T2 != NULL)
        T2->parent = y;

    y->parent = x;

    updateHeight(y);
    updateHeight(x);

    return x;
}

AVLNode *balanceNode(AVLNode *node)
{
    updateHeight(node);

    int balance = getBalance(node);

    if (balance > 1)
    {
        if (getBalance(node->left) < 0)
            node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1)
    {
        if (getBalance(node->right) > 0)
            node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVLNode *createNode(int data)
{
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->data = data;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

AVLNode *insert(AVLNode *node, int data)
{
    if (node == NULL)
    {
        node = createNode(data);
        return node;
    }

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; // Duplicate values are not allowed

    node->parent = NULL;

    return balanceNode(node);
}

AVLNode *search(AVLNode *node, int data)
{
    if (node == NULL)
        return NULL;
    else if (data < node->data)
        return search(node->left, data);
    else if (data > node->data)
        return search(node->right, data);
    else
        return node;
}

AVLNode *findMin(AVLNode *node)
{
    if (node == NULL)
        return NULL;
    else if (node->left == NULL)
        return node;
    else
        return findMin(node->left);
}

AVLNode *findMax(AVLNode *node)
{
    if (node == NULL)
        return NULL;
    else if (node->right == NULL)
        return node;
    else
        return findMax(node->right);
}

AVLNode *findSuccessor(AVLNode *node)
{
    if (node == NULL)
        return NULL;
    else if (node->right != NULL)
        return findMin(node->right);
    else
    {
        AVLNode *temp = node->parent;
        while (temp != NULL && node == temp->right)
        {
            node = temp;
            temp = temp->parent;
        }
        return temp;
    }
}

AVLNode *findPredecessor(AVLNode *node)
{
    if (node == NULL)
        return NULL;
    else if (node->left != NULL)
        return findMax(node->left);
    else
    {
        AVLNode *temp = node->parent;
        while (temp != NULL && node == temp->left)
        {
            node = temp;
            temp = temp->parent;
        }
        return temp;
    }
}

AVLNode *deleteNode(AVLNode *node, int data)
{
    if (node == NULL)
        return node;

    if (data < node->data)
        node->left = deleteNode(node->left, data);
    else if (data > node->data)
        node->right = deleteNode(node->right, data);
    else
    {
        if (node->left == NULL)
        {
            AVLNode *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            AVLNode *temp = node->left;
            free(node);
            return temp;
        }
        else
        {
            AVLNode *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
    }

    return balanceNode(node);
}

void printInorder(AVLNode *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d\t", node->data);
    printInorder(node->right);
}

void printPreorder(AVLNode *node)
{
    if (node == NULL)
        return;
    printf("%d\t", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(AVLNode *node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d\t", node->data);
}
