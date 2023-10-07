#include <stdio.h>

int pointerOperations = 0;
int comparisons = 0;

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
    // One Comparision
    comparisons++;
    if (root == NULL)
        return -1;
    else
        return root->height;
}

int max(int a, int b)
{
    // One Comparision
    comparisons++;
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
    // Three Pointer Operations
    pointerOperations += 3;
    return newNode;
}

BSTNode *insert(BSTNode *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        // one Comparision and one pointer operation
        pointerOperations++;
        comparisons++;
        return root;
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
        root->left->parent = root;
        // Two Comparisions and two pointer operation
        pointerOperations += 2;
        comparisons += 2;
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
        root->right->parent = root;
        // Three Comparisions and two pointer operation
        pointerOperations += 2;
        comparisons += 3;
    }
    else
    {
        // Three Comparisions
        comparisons += 3;
        return root; // Duplicate values are not allowed
    }

    root->height = 1 + max(height(root->left), height(root->right));
    // One Pointer operation
    pointerOperations++;

    return root;
}

BSTNode *search(BSTNode *root, int data)
{
    if (root == NULL)
    { // One Comparision
        comparisons++;
        return NULL;
    }
    else if (root->data == data)
    { // Two Comparisions
        comparisons += 2;
        return root;
    }
    else if (data < root->data)
    { // Three Comparisions
        comparisons += 3;
        return search(root->left, data);
    }
    else
    { // Three Comparisions
        comparisons += 3;
        return search(root->right, data);
    }
}

BSTNode *findMin(BSTNode *root)
{
    if (root == NULL)
    { // One Comparision
        comparisons++;
        return NULL;
    }
    else if (root->left == NULL)
    { // Two Comparisions
        comparisons += 2;
        return root;
    }
    else
    { // Two Comparisions
        comparisons += 2;
        return findMin(root->left);
    }
}

BSTNode *findMax(BSTNode *root)
{
    if (root == NULL)
    { // One Comparision
        comparisons++;
        return NULL;
    }
    else if (root->right == NULL)
    { // Two Comparisions
        comparisons += 2;
        return root;
    }
    else
    { // Two Comparisions
        comparisons += 2;
        return findMax(root->right);
    }
}

BSTNode *findSuccessor(BSTNode *root)
{
    if (root == NULL)
    { // One Comparision
        comparisons++;
        return NULL;
    }
    else if (root->right != NULL)
    { // Two Comparisions
        comparisons += 2;
        return findMin(root->right);
    }
    else
    {
        BSTNode *successor = root->parent;
        BSTNode *current = root;
        while (successor != NULL && current == successor->right)
        {
            current = successor;
            successor = successor->parent;
            // Two Comparisions and two pointer operations
            comparisons += 2;
            pointerOperations += 2;
        }
        // Three Comparisions or Four Comparisions (Assuming in general 3 comparisions)
        /* The above has two conditions to check which is then joined with an AND operator so if we
        consider the worst case then it will be 4 comparisions
        */
        comparisons += 4;
        return successor;
    }
}

BSTNode *findPredecessor(BSTNode *root)
{
    if (root == NULL)
    { // One Comparision
        comparisons++;
        return NULL;
    }
    else if (root->left != NULL)
    { // Two Comparisions
        comparisons += 2;
        return findMax(root->left);
    }
    else
    {
        BSTNode *predecessor = root->parent;
        BSTNode *current = root;
        // Two Pointer Operations
        pointerOperations += 2;
        while (predecessor != NULL && current == predecessor->left)
        {
            current = predecessor;
            predecessor = predecessor->parent;
            // Two Comparisions and two pointer operations
            comparisons += 2;
            pointerOperations += 2;
        }
        // Three Comparisions or Four Comparisions (Assuming in general 3 comparisions)
        /* The above has two conditions to check which is then joined with an AND operator so if we
        consider the worst case then it will be 4 comparisions
        */
        comparisons += 4;
        return predecessor;
    }
}

BSTNode *deleteNode(BSTNode *root, int data)
{
    if (root == NULL)
    { // One Comparision
        comparisons++;
        return NULL;
    }
    else if (data < root->data)
    { // Two Comparisions and one pointer operation
        comparisons += 2;
        root->left = deleteNode(root->left, data);
        pointerOperations++;
    }
    else if (data > root->data)
    { // Three Comparisions and one pointer operation
        comparisons += 3;
        root->right = deleteNode(root->right, data);
        pointerOperations++;
    }
    else
    {
        // Three Comparisions
        comparisons += 3;
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            // Two Comparisions and one pointer operation
            comparisons += 2;
            pointerOperations++;
        }
        else if (root->left == NULL)
        {
            BSTNode *temp = root;
            root = root->right;
            free(temp);
            // Three Comparisions and two pointer operation
            comparisons += 3;
            pointerOperations += 2;
        }
        else if (root->right == NULL)
        {
            BSTNode *temp = root;
            root = root->left;
            free(temp);
            // Three Comparisions and two pointer operation
            comparisons += 3;
            pointerOperations += 2;
        }
        else
        {
            BSTNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
            // Three Comparisions and three pointer operation
            comparisons += 3;
            pointerOperations += 3;
        }
    }
    // One Comparision
    comparisons++;
    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    // One Pointer operation
    pointerOperations++;
    return root;
}

void printInorder(BSTNode *root)
{
    // One Comparision
    comparisons++;
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d\t", root->data);
    printInorder(root->right);
}

void printPreorder(BSTNode *root)
{
    // One Comparision
    comparisons++;
    if (root == NULL)
        return;
    printf("%d\t", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(BSTNode *root)
{
    // One Comparision
    comparisons++;
    if (root == NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d\t", root->data);
}

void resetCountersBST()
{
    pointerOperations = 0;
    comparisons = 0;
}
