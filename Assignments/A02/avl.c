#include <stdio.h>

int pointerOperations = 0;
int comparisons = 0;

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
    // One comparasion
    comparisons++;
    if (node == NULL)
        return -1;
    return node->height;
}

int max(int a, int b)
{
    // One comparasion
    comparisons++;
    return (a > b) ? a : b;
}

int getBalance(AVLNode *node)
{
    // One comparasion
    comparisons++;
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

void updateHeight(AVLNode *node)
{
    // One comparasion
    comparisons++;
    if (node == NULL)
        return;
    // One Pointer Operation
    pointerOperations++;
    node->height = 1 + max(height(node->left), height(node->right));
}

AVLNode *leftRotate(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;
    // Four Pointer Operations
    pointerOperations += 4;

    if (T2 != NULL)
        // One Pointer Operation
        pointerOperations++;
    T2->parent = x;

    x->parent = y;
    // One Pointer Operation and one Comparasion
    pointerOperations++;
    comparisons++;

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
    // Four Pointer Operations
    pointerOperations += 4;

    if (T2 != NULL)
        // One Pointer Operation
        pointerOperations++;
    T2->parent = y;

    y->parent = x;
    // One Pointer Operation and one Comparasion
    pointerOperations++;
    comparisons++;

    updateHeight(y);
    updateHeight(x);

    return x;
}

AVLNode *balanceNode(AVLNode *node)
{
    updateHeight(node);

    int balance = getBalance(node);

    // One Comparasion
    comparisons++;
    if (balance > 1)
    {
        // One Comparasion
        comparisons++;
        if (getBalance(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            // One Pointer Operation
            pointerOperations++;
        }

        return rightRotate(node);
    }
    // One Comparasion
    comparisons++;
    if (balance < -1)
    {
        // One Comparasion
        comparisons++;
        if (getBalance(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            // One Pointer Operation
            pointerOperations++;
        }

        return leftRotate(node);
    }
    return node;
}

AVLNode *createNode(int data)
{
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->data = data;
    newNode->height = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    // Three Pointer Operations
    pointerOperations += 3;
    return newNode;
}

AVLNode *insert(AVLNode *node, int data)
{
    if (node == NULL)
    {
        node = createNode(data);
        // one Comparision and one pointer operation
        pointerOperations++;
        comparisons++;
        return node;
    }
    else if (data < node->data)
    {
        node->left = insert(node->left, data);
        node->left->parent = node;
        // two Comparision and two pointer operation
        pointerOperations += 2;
        comparisons += 2;
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
        node->right->parent = node;
        // three Comparision and two pointer operation
        pointerOperations += 2;
        comparisons += 3;
    }
    else
    {
        comparisons += 3;
        return node; // Duplicate values are not allowed
    }

    return balanceNode(node);
}

AVLNode *search(AVLNode *root, int data)
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

AVLNode *findMin(AVLNode *root)
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

AVLNode *findMax(AVLNode *root)
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

AVLNode *findSuccessor(AVLNode *root)
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
        AVLNode *successor = root->parent;
        AVLNode *current = root;
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

AVLNode *findPredecessor(AVLNode *root)
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
        AVLNode *predecessor = root->parent;
        AVLNode *current = root;
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

AVLNode *deleteNode(AVLNode *node, int data)
{
    if (node == NULL)
    {
        // One comparision
        comparisons++;
        return node;
    }
    if (data < node->data)
    {
        // Two Comparisions
        comparisons += 2;
        node->left = deleteNode(node->left, data);
        // One pointer operations
        pointerOperations++;
    }
    else if (data > node->data)
    {
        // Three Comparisions
        comparisons += 3;
        node->right = deleteNode(node->right, data);
        // One pointer operation
        pointerOperations++;
    }
    else
    {
        // Three Comparasions
        comparisons += 3;
        if (node->left == NULL)
        {
            // One comparision
            comparisons++;
            AVLNode *temp = node->right;
            // One pointer operation
            pointerOperations++;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            // Two Comparision
            comparisons += 2;
            AVLNode *temp = node->left;
            // One pointer operation
            pointerOperations++;
            free(node);
            return temp;
        }
        else
        {
            // Two Comparasions
            comparisons += 2;
            AVLNode *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
            // Three pointer Opreations
            pointerOperations += 3;
        }
    }

    return balanceNode(node);
}

void printInorder(AVLNode *node)
{
    // One comparision
    comparisons++;
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d\t", node->data);
    printInorder(node->right);
}

void printPreorder(AVLNode *node)
{
    // One comparision
    comparisons++;
    if (node == NULL)
        return;
    printf("%d\t", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(AVLNode *node)
{
    // One comparision
    comparisons++;
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d\t", node->data);
}

void resetCountersAVL()
{
    pointerOperations = 0;
    comparisons = 0;
}
