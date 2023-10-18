# Random Sequence Generator in C

This C code provides a utility for generating random sequences of numbers and saving them to a file. It allows you to specify the number of sequences, the number of elements in each sequence, and the output filename.

## Table of Contents

- [Introduction](#introduction)
- [Code Description](#code-description)
- [Functions](#functions)

## Introduction

Generating random sequences of numbers can be useful in various applications, such as testing algorithms, simulations, and data analysis. This C code provides a simple utility to create multiple random sequences and save them to a file for further use.

## Code Description

- The code defines a function `randomNumberGenerator` that generates a random sequence of numbers with unique values.
- It uses a flag array to mark used indexes and ensures that each generated value is unique within the sequence.
- The code provides a function `inputGenerator` to create and save multiple random sequences to a file.
- The user can specify the output filename, the total number of sequences (`T`), and the number of elements in each sequence (`M`).
- It uses a different seed for the random number generator to generate distinct random sequences.

## Functions

The code includes the following functions:

- `randomNumberGenerator`: Generates a random sequence of unique numbers with specified parameters.
- `inputGenerator`: Takes user input for the output filename, the total number of sequences, and the number of elements in each sequence. It then generates and saves random sequences to the file.

# Binary Search Tree (BST) Operations in C

This C code provides an implementation of basic Binary Search Tree (BST) operations, including insertion, deletion, searching, and various utility functions. The code also includes counters for tracking the number of pointer operations and comparisons made during the operations.

## Table of Contents

- [Introduction](#introduction)
- [Code Description](#code-description)
- [Functions](#functions)
- [Counters](#counters)


## Introduction

A Binary Search Tree is a data structure used to organize and manage data efficiently. This code provides a C implementation of essential BST operations and includes counters to keep track of the number of comparisons and pointer operations involved in these operations.

## Code Description

- The code defines a `BSTNode` structure to represent a node in the Binary Search Tree.
- It implements the following BST operations:
  - `insert`: Inserts a new node with the given data into the BST.
  - `search`: Searches for a node with a specific data value.
  - `findMin` and `findMax`: Find the minimum and maximum values in the BST, respectively.
  - `findSuccessor` and `findPredecessor`: Find the successor and predecessor nodes of a given node in the BST.
  - `deleteNode`: Deletes a node with a specific data value from the BST.
- Utility functions for tree traversal are included, such as `printInorder`, `printPreorder`, and `printPostorder`.
- Counters are used to track the number of pointer operations and comparisons made during the operations.

## Functions

The code includes the following functions:

- `createNode`: Creates a new BST node.
- `height`: Returns the height of a given BST node.
- `max`: Returns the maximum of two integers.
- `resetCounters`: Resets the comparison and pointer operation counters.
- Various BST operations as described above.

## Counters

Two counters are used to track the efficiency of the BST operations:

- `pointerOperations`: Counts the number of pointer operations.
- `comparisons`: Counts the number of comparisons made during the operations.

These counters are reset using the `resetCounters` function.

# Binary Search Tree (BST) Analysis in C

This C code performs an analysis of a Binary Search Tree (BST) by repeatedly inserting and deleting elements from sequences in an input file. The analysis tracks tree heights and the number of comparisons and pointer operations made during these operations.

## Table of Contents

- [Introduction](#introduction)
- [Code Description](#code-description)
- [Functions](#functions)

## Introduction

Analyzing the behavior and efficiency of data structures, such as Binary Search Trees (BST), is crucial in various computer science applications. This C code conducts an analysis of BSTs by performing a sequence of insertions and deletions and recording relevant metrics.

## Code Description

- The code reads sequences of integers from an input file, provided by the user.
- It repeatedly inserts elements from the sequences into a BST and subsequently deletes a subset of these elements.
- The analysis is repeated for multiple iterations.
- The height of the BST and the number of comparisons and pointer operations are tracked during each iteration.
- The results, including tree heights and operation counts, are saved to an output file.

## Functions

The code includes the following functions:

- `indexToDelete` and `keysToDelete`: Generate a set of indices and keys to delete from the BST.
- `analyzer`: Performs BST analysis by repeatedly inserting and deleting elements and recording relevant metrics.

# AVL Tree Operations in C

This C code provides an implementation of AVL (Adelson-Velsky and Landis) tree operations, which are a type of self-balancing binary search tree. The code includes functions for inserting, deleting, searching, and various utility functions. It also keeps track of the number of pointer operations and comparisons made during the operations.

## Table of Contents

- [Introduction](#introduction)
- [Code Description](#code-description)
- [Functions](#functions)
- [Counters](#counters)

## Introduction

AVL trees are self-balancing binary search trees that maintain their balance by ensuring that the heights of the two child subtrees of any node differ by at most one.

This code provides a C implementation of essential AVL tree operations, including insertion, deletion, searching, and various utility functions. It also includes counters to keep track of the number of comparisons and pointer operations involved in these operations.

## Code Description

- The code defines an `AVLNode` structure to represent a node in the AVL tree.
- It implements the following AVL tree operations:
  - `insert`: Inserts a new node with the given data into the AVL tree and rebalances the tree if necessary.
  - `search`: Searches for a node with a specific data value.
  - `findMin` and `findMax`: Find the minimum and maximum values in the AVL tree, respectively.
  - `findSuccessor` and `findPredecessor`: Find the successor and predecessor nodes of a given node in the AVL tree.
  - `deleteNode`: Deletes a node with a specific data value from the AVL tree and rebalances the tree.
- Utility functions for tree traversal are included, such as `printInorder`, `printPreorder`, and `printPostorder`.
- Counters are used to track the number of pointer operations and comparisons made during the operations.

## Functions

The code includes the following functions:

- `createNode`: Creates a new AVL tree node.
- `height`: Returns the height of a given AVL tree node.
- `max`: Returns the maximum of two integers.
- `getBalance`: Computes the balance factor of a given AVL tree node.
- `updateHeight`: Updates the height of a given AVL tree node based on its children.
- `leftRotate` and `rightRotate`: Perform left and right rotations to balance the tree.
- `balanceNode`: Balances the AVL tree after insertion or deletion.
- Various AVL tree operations as described above.

## Counters

Two counters are used to track the efficiency of the AVL tree operations:

- `pointerOperations`: Counts the number of pointer operations.
- `comparisons`: Counts the number of comparisons made during the operations.

These counters are reset using the `resetCounters` function.

# AVL Tree Analysis in C

This C code performs an analysis of an AVL (Adelson-Velsky and Landis) tree by repeatedly inserting and deleting elements from sequences in an input file. The analysis tracks tree heights and the number of comparisons and pointer operations made during these operations.

## Table of Contents

- [Introduction](#introduction)
- [Code Description](#code-description)
- [Functions](#functions)

## Introduction

Analyzing the behavior and efficiency of data structures, such as AVL trees, is crucial in various computer science applications. This C code conducts an analysis of AVL trees by performing a sequence of insertions and deletions and recording relevant metrics.

## Code Description

- The code reads sequences of integers from an input file, provided by the user.
- It repeatedly inserts elements from the sequences into an AVL tree and subsequently deletes a subset of these elements.
- The analysis is repeated for multiple iterations.
- The height of the AVL tree and the number of comparisons and pointer operations are tracked during each iteration.
- The results, including tree heights and operation counts, are saved to an output file.

## Functions

The code includes the following functions:

- `indexToDelete` and `keysToDelete`: Generate a set of indices and keys to delete from the AVL tree.
- `analyzer`: Performs AVL tree analysis by repeatedly inserting and deleting elements and recording relevant metrics.

# BST and AVL Tree Analysis in C (main.c)

This C program allows you to choose between analyzing Binary Search Trees (BST) or AVL trees by uncommenting the relevant source file. You can generate random input files for analysis or provide your own input files.

## Table of Contents

- [Introduction](#introduction)
- [Code Description](#code-description)
- [Usage](#usage)

## Introduction

Analyzing the behavior and efficiency of data structures, such as Binary Search Trees (BST) and AVL trees, is crucial in various computer science applications. This C program provides you with the flexibility to perform detailed analysis on these tree structures.

## Code Description

- The program allows you to choose between analyzing Binary Search Trees (BST) or AVL trees by uncommenting the relevant source file.
- You can choose to generate new input files with random sequences or provide your own input files.
- For analysis, you need to specify the input filename and the output filename.
- The program performs multiple iterations of tree insertions and deletions.
- It tracks tree heights and the number of comparisons and pointer operations made during these operations.
- The results are saved to the specified output file.

## Usage

1. Compile the code based on your selection (BST or AVL) and your input source (random input generator or your own input file).

2. To generate new random input files, uncomment the line for `inputGenerator()` and comment out all other lines. Compile and run the program to generate new input files.

3. To analyze Binary Search Trees (BST), uncomment the `#include "analysisBST.c"` line, and provide the input and output filenames when prompted.

4. To analyze AVL trees, uncomment the `#include "analysisAVL.c"` line, and provide the input and output filenames when prompted.

5. Compile the code using a C compiler, e.g., `gcc -o main.out main.c`.

6. Run the compiled program, e.g., `./main.out`.

7. Follow the on-screen prompts to perform the selected analysis.





