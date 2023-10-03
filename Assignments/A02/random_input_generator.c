#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int *random_number_generator(int M, int N)
{
    int in, im = 0;
    int *vector = (int *)malloc(sizeof(int) * M);
    // Flag array to mark used indexes
    int *is_used = (int *)calloc(N, sizeof(int));

    // Initialize random number generator

    for (in = N - M; in < N && im < M; ++in)
    {
        int r = rand() % (in + 1); /* generate a random number 'r' */

        if (is_used[r])
            /* we already have 'r' */
            r = in; /* use 'in' instead of the generated number */

        assert(!is_used[r]);
        vector[im++] = r + 1; /* +1 since your range begins from 1 */
        is_used[r] = 1;
    }
    assert(im == M);
    free(is_used);
    return vector;
}

void main()
{
    int M, N, T;
    char filename[100];

    // Getting the Filename, T and M from user
    printf("Enter Filename to save the numbers:");
    scanf("%s", filename);
    printf("Enter total number of input sequence required: ");
    scanf("%d", &T);
    printf("Enter total number of elements in each sequence: ");
    scanf("%d", &M);
    N = M * T; // Total number of elements in the file

    // Opening the file
    FILE *fp = fopen(filename, "w");

    for (int i = 0; i < T; i++)
    {
        /*Intializes random number generator with seed so that different
            random sequences are generated*/
        unsigned int seed = 2 * i + 1;
        srand(seed);

        // Generating random sequence of numbers
        int *vector = random_number_generator(M, N);

        // Writing the sequence to file
        for (int j = 0; j < M; j++)
            fprintf(fp, "%d ", vector[j]);
        fprintf(fp, "\n");
    }
    fclose(fp); // Closing the file
}