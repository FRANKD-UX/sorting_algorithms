#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* Doubly linked list data structure */
typedef struct listint_s 
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Prototype for print functions */
void print_array(const int *array, size_t size); /* array printing */
void print_list(const listint_t *list);          /* linked list printing */

/* Task function prototypes */
int len_list(listint_t *h);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_recursion(int *array, int left, int right, size_t size);
int partition(int *array, int left, int right, size_t size);
void shell_sort(int *array, size_t size);
void switch_nodes(listint_t **list, listint_t **p);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_recursion(int *arr, int *array, size_t left, size_t right);
void merge_subarray(int *arr, int *array, size_t left, size_t middle, size_t right);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t s, size_t root, size_t size);
void radix_sort(int *array, size_t size);
void count_sort_LSD(int *array, size_t size, size_t lsd);
void quick_sort_hoare(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void swap_nodes(listint_t *left, listint_t *right);

#endif /* SORT_H */
