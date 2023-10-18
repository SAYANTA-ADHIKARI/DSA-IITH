#include <stdio.h>
// #include "random_input_generator.c"
// Uncomment the following line to analyze BST (Comment out all other lines)
#include "analysisBST.c"
// Uncomment the following line to analyze AVL (Comment out all other lines)
// #include "analysisAVL.c"

void main()
{
    // Uncomment the following line to generate new input file (Comment out all other lines)
    // inputGenerator();

    // Uncomment the following line to analyze BST (Comment out all other lines)
    char *inputfilename = (char *)malloc(sizeof(char) * 100);
    char *outputfilename = (char *)malloc(sizeof(char) * 100);
    printf("Enter input filename: ");
    scanf("%s", inputfilename);
    printf("Enter output filename: ");
    scanf("%s", outputfilename);
    analyzer(inputfilename, outputfilename);
    free(inputfilename);
    free(outputfilename);
}