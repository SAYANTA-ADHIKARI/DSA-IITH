#include <stdio.h>

int pointerOperationsBST = 0;
int comparisonsBST = 0;

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
    // One comparasion
    if (root == NULL)
        return -1;
    else
        return root->height;
}

int max(int a, int b)
{
    // One comparasion
    return (a > b) ? a : b;
}

BSTNode *createNode(int data)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->data = data;
    newNode->height = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    // Five Pointer Operations
    return newNode;
}

BSTNode *insert(BSTNode *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        // one comparasion and one pointer operation
        return root;
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
        root->left->parent = root;
        // Two Comparasions and two pointer operation
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
        root->right->parent = root;
        // Three Comparasions and two pointer operation
    }
    else
    {
        // Three Comparasions
        return root; // Duplicate values are not allowed
    }

    root->height = 1 + max(height(root->left), height(root->right));
    // One Pointer operation

    return root;
}

BSTNode *search(BSTNode *root, int data)
{
    if (root == NULL)
        // One Comparasion
        return NULL;
    else if (root->data == data)
        // Two Comparasions
        return root;
    else if (data < root->data)
        // Three Comparasions
        return search(root->left, data);
    else
        // Three Comparasions
        return search(root->right, data);
}

BSTNode *findMin(BSTNode *root)
{
    if (root == NULL)
        // One Comparasion
        return NULL;
    else if (root->left == NULL)
        // Two Comparasions
        return root;
    else
        // Two Comparasions
        return findMin(root->left);
}

BSTNode *findMax(BSTNode *root)
{
    if (root == NULL)
        // One Comparasion
        return NULL;
    else if (root->right == NULL)
        // Two Comparasions
        return root;
    else
        // Two Comparasions
        return findMax(root->right);
}

BSTNode *findSuccessor(BSTNode *root)
{
    if (root == NULL)
        // One Comparasion
        return NULL;
    else if (root->right != NULL)
        // Two Comparasions
        return findMin(root->right);
    else
    {
        BSTNode *successor = root->parent;
        BSTNode *current = root;
        while (successor != NULL && current == successor->right)
        {
            current = successor;
            successor = successor->parent;
            // Two Comparasions and two pointer operations
        }
        // Three Comparasions
        return successor;
    }
}

BSTNode *findPredecessor(BSTNode *root)
{
    if (root == NULL)
        // One Comparasion
        return NULL;
    else if (root->left != NULL)
        // Two Comparasions
        return findMax(root->left);
    else
    {
        BSTNode *predecessor = root->parent;
        BSTNode *current = root;
        while (predecessor != NULL && current == predecessor->left)
        {
            current = predecessor;
            predecessor = predecessor->parent;
            // Two Comparasions and two pointer operations
        }
        // Three Comparasions
        return predecessor;
    }
}

BSTNode *deleteNode(BSTNode *root, int data)
{
    if (root == NULL)
        // One Comparasion
        return NULL;
    else if (data < root->data)
        // Two Comparasions and one pointer operation
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        // Three Comparasions and one pointer operation
        root->right = deleteNode(root->right, data);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            // Two Comparasions and one pointer operation
        }
        else if (root->left == NULL)
        {
            BSTNode *temp = root;
            root = root->right;
            free(temp);
            // Two Comparasions and one pointer operation
        }
        else if (root->right == NULL)
        {
            BSTNode *temp = root;
            root = root->left;
            free(temp);
            // Three Comparasions and one pointer operation
        }
        else
        {
            BSTNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
            // Three Comparasions and three pointer operation
        }
    }
    // One Comparasion
    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    // One Pointer operation
    return root;
}

void printInorder(BSTNode *root)
{
    // One Comparasion
    if (root == NULL)
        return;
    printInorder(root->left);
    // One Pointer operation
    printf("%d\t", root->data);
    printInorder(root->right);
}

void printPreorder(BSTNode *root)
{
    // One Comparasion
    if (root == NULL)
        return;
    // One Pointer operation
    printf("%d\t", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(BSTNode *root)
{
    // One Comparasion
    if (root == NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    // One Pointer operation
    printf("%d\t", root->data);
}

void resetCountersBST()
{
    pointerOperationsBST = 0;
    comparisonsBST = 0;
}
