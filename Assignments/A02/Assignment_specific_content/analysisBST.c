#include <stdio.h>
#include <stdlib.h>
#include "random_input_generator.c"
#include "bst.c"

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
void analyzer(char *inputfilename, char *outputfilename)
{
    int *arr = (int *)malloc(sizeof(int) * 1000);
    FILE *fp = fopen(inputfilename, "r");
    FILE *fo = fopen(outputfilename, "w");
    for (int j = 0; j < 100; j++)
    {
        printf("Analysing %dth iteration\n", j + 1);
        for (int i = 0; i < 1000; i++)
        {
            fscanf(fp, "%d", &arr[i]);
        }
        srand((unsigned int)(2 * j + 1));
        int *deleteKeys = keysToDelete(100, arr, 1000);
        // Creating a BST
        BSTNode *root = NULL;
        for (int i = 0; i < 1000; i++)
        {
            root = insert(root, arr[i]);
        }
        int height = root->height;
        // Deleting Keys
        for (int i = 0; i < 100; i++)
        {
            root = deleteNode(root, deleteKeys[i]);
        }
        int newHeight = root->height;
        fprintf(fo, "Height: %d\tNew Height: %d\tComparisions: %d\tPointer Operations: %d\n", height, newHeight, comparisons, pointerOperations);
        resetCounters();
    }
    fclose(fp);
    fclose(fo);
    free(arr);
}
