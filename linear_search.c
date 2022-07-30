#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int check_arguments(int max, char **a);

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Usage: ./linear search_number [numbers]\n");
        return 2;
    }
    if (!check_arguments(argc, argv))
    {
        printf("Usage: ./linear search_number [numbers]\n");
        return 3;
    }
    int search_number = atoi(argv[1]);

    for (int i = 2, n = argc; i < n; i++)
    {
        if (search_number == atoi(argv[i]))
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
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