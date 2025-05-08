#include <stdio.h>
#define MAX 100

int a[MAX], n;

void insert()
{
    printf("Enter number of elements to sort:");
    scanf("%d", &n);

    printf("\nEnter elements one by one:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter element:");
        scanf("%d", &a[i]);
        printf("\n");
    }
}

int select_max(int j)
{
    // This method returns the position of the max element from a[1...j]
    // j is the index upto which we will find max, from 1 to j
    int max = a[0];
    int pos = 0;

    for (int i = 1; i <= j; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            pos = i;
        }
    }

    return pos;
}

void selection_sort()
{
    for (int i = n - 1; i >= 2; i--)
    {
        int pos = select_max(i);
        // Send the max element to the end of the array and the end element in the place of max
        int t = a[i];
        a[i] = a[pos];
        a[pos] = t;
    }
}

void display()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    // Taking the elements input
    insert();
    printf("Your elements:\n");
    display();

    // Performing selection sort
    selection_sort();

    // Displaying final result
    printf("\nAfter sorting:\n");
    display();
    printf("\n");
}