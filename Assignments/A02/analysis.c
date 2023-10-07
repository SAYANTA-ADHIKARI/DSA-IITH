#include <stdio.h>
#include <stdlib.h>
#include "random_input_generator.c"
/*Which ever you want to analysis, include that. AVL Tree or BST Tree*/
#include "bst.c"
// #include "avl.c"

int *indexToDelete(int count, int upperBound)
{
    return randomNumberGenerator(count, upperBound);
}
int *keysToDelete(int count, int *arr, int length)
{
    int *keys = (int *)malloc(sizeof(int) * count);
    int *index = indexToDelete(count, length);
    for (int i = 0; i < count; i++)
    {
        keys[i] = arr[index[i]];
    }
    return keys;
}