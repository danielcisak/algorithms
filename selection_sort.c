#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int check_arguments(int max, char **a);
void selection(int n[], int length);
void print_data(int n[], int length);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: ./selection_sort [positive numbers]\n");
        return 1;
    }
    if (!check_arguments(argc, argv))
    {
        printf("Usage: ./selection_sort [positive numbers]\n");
        return 2;
    }

    const int length = argc - 1;
    int numbers[length];

    for (int i = 0; i < length; i++)
    {
        numbers[i] = atoi(argv[i + 1]);
    }

    print_data(numbers, length);

    selection(numbers, length);
    print_data(numbers, length);
    return 0;
}

int check_arguments(int max, char **a)
{
    for (int i = 1; i < max; i++)
    {
        for (int j = 0, n = strlen(a[i]); j < n; j++)
        {
            if (!isdigit(a[i][j]))
            {
                return 0;
            }
        }
    }
    return 1;
}

void selection(int n[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int smallest = n[i];
        int index = i;
        for (int j = i + 1; j < length; j++)
        {
            if (smallest > n[j])
            {
                smallest = n[j];
                index = j;
            }
        }
        int tmp = n[i];
        n[i] = n[index];
        n[index] = tmp;
    }
}

void print_data(int n[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%i ", n[i]);
    }
    printf("\n");
}