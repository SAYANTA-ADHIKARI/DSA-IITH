#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int x;
    int y;
} point;

void print_point(point p)
{
    printf("Point: X=%d, Y=%d\n", p.x, p.y);
}

typedef struct
{
    point *arr;
    int head;
    int tail;
    int MAX_LENGTH;
    int total_elements;
} Deque;

void print_deque(Deque *d)
{
    int temp_head = d->head;
    int elements = d->total_elements;
    printf("Printing the Deque with %d elements and total capacity of %d\n", d->total_elements, d->MAX_LENGTH);
    while (elements != 0)
    {
        print_point(d->arr[temp_head]);
        printf("\t|\n\tV\n");
        temp_head = (temp_head + 1) % d->MAX_LENGTH;
        elements--;
    }
    if (d->total_elements != 0)
        printf("\nEND\n");
}

Deque *make_deque(int capacity, int head_idx)
{
    if (head_idx > capacity)
    {
        printf("Wrong Head Index Provided!!");
        exit(0);
    }
    else
    {
        Deque *d = malloc(sizeof(Deque));
        d->MAX_LENGTH = capacity;
        d->total_elements = 0;
        d->arr = malloc(sizeof(point) * capacity);
        d->head = head_idx;
        d->tail = head_idx;
        return d;
    }
}

void add_first(point p, Deque *d)
{
    if (d->total_elements == d->MAX_LENGTH)
    {
        printf("Overflow\n");
        exit(0);
    }
    else
    {
        if (d->head == 0)
            d->head = d->MAX_LENGTH - 1;
        else
            d->head--;
        d->arr[d->head] = p;
        d->total_elements++;
    }
}

void add_last(point p, Deque *d)
{
    if (d->total_elements == d->MAX_LENGTH)
    {
        printf("Overflow\n");
        exit(0);
    }
    else
    {
        d->arr[d->tail] = p;
        d->total_elements++;
        if (d->tail == d->MAX_LENGTH - 1)
            d->tail = 0;
        else
            d->tail++;
    }
}

void remove_first(Deque *d, bool verbose)
{
    if (d->total_elements == 0)
    {
        printf("Underflow\n");
        exit(0);
    }
    else
    {
        if (verbose == true)
        {
            printf("Removing element at %d\n", d->head);
            print_point(d->arr[d->head]);
        }
        if (d->head == d->MAX_LENGTH - 1)
            d->head = 0;
        else
            d->head++;
        d->total_elements--;
    }
}

void remove_last(Deque *d, bool verbose)
{
    if (d->total_elements == 0)
    {
        printf("Underflow\n");
        exit(0);
    }
    else
    {
        if (d->tail == 0)
            d->tail = d->MAX_LENGTH - 1;
        else
            d->tail--;
        if (verbose == true)
        {
            printf("Removing element at %d\n", d->head);
            print_point(d->arr[d->head]);
        }
        d->total_elements--;
    }
}

bool is_empty(Deque *d)
{
    if (d->total_elements == 0)
        return true;
    return false;
}