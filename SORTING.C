#include <stdio.h>
#include <conio.h>
void bubbleSort(int arr[], int n)
{
    int i, j,temp;
    for (i = 0; i < n - 1; i++)
    {
	for (j = 0; j < n - i - 1; j++)
	{
	    if (arr[j] > arr[j + 1])
	    {
		temp = arr[j];
		arr[j] = arr[j + 1];
			arr[j + 1] = temp;
	    }
	}
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    int temp;
    for (i = 0; i < n - 1; i++)
    {
	min_idx = i;
	for (j = i + 1; j < n; j++)
	{
	    if (arr[j] < arr[min_idx])
	    {
		min_idx = j;
	    }
	}
	temp = arr[min_idx];
	arr[min_idx] = arr[i];
	arr[i] = temp;
    }
}

int main()
{
    int arr[] = {12, 34, 1, 0, 35, 12, 57};
    int arr2[] = {12,34,1,0,35,12,57};
    int i;
    int n = sizeof(arr) / sizeof(arr[0]);
    clrscr();
    printf("Array before starting: \n");
    for (i = 0; i < n; i++)
    {
	printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);

    printf("Array after Bubble Sort: \n");
    for (i = 0; i < n; i++)
    {
	printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr2, n);

    printf("Array after Selection Sort: \n");
    for (i = 0; i < n; i++)
    {
	printf("%d ", arr2[i]);
    }
    printf("\n");
    getch();
    return 0;
}