/*
Q1. Write a C/C++ program to implement below mentioned Searching
and Sorting Techniques.
(a) Bubble Sort
(b) Selection Sort
(c) Insertion Sort
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void swap(int *a, int *b);
void insertionSort(int arr[], int size);

int main()
{
	while (1) // Infinite loop for menu
	{
		int size, choice;
		printf("\nEnter size of array: ");
		scanf("%d", &size);
		int arr[size]; // Declare array of given size

		// Input elements into the array
		for (int i = 0; i < size; i++)
		{
			printf("\nEnter element for index %d :", i);
			scanf("%d", &arr[i]);
		}

		// Display the input array
		printf("\nYour array is: ");
		for (int i = 0; i < size; i++)
		{
			printf("%d ", arr[i]);
		}

		// Display sorting options
		printf("\n\nMenu:\n");
		printf("1. Bubble sort\n");
		printf("2. Selection sort\n");
		printf("3. Insertion sort\n");
		printf("4. Quit\n");

		printf("Enter your choice: ");
		scanf("%d", &choice);

		// Perform sorting based on user choice
		switch (choice)
		{
		case 1:
			bubbleSort(arr, size);
			break;

		case 2:
			selectionSort(arr, size);
			break;

		case 3:
			insertionSort(arr, size);
			break;

		case 4:
			exit(1); // Exit the program

		default:
			printf("Invalid choice");
		}
	}
	return 0;
}

// Bubble sort implementation
void bubbleSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) // Swap if in wrong order
			{
				int temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	// Display sorted array
	printf("\n--------------------------------------");
	printf("\nSorted array is: ");
	for (int k = 0; k < size; k++)
	{
		printf("%d ", arr[k]);
	}
	printf("\n");
	printf("--------------------------------------\n");
}

// Selection sort implementation
void selectionSort(int arr[], int size)
{
	int i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i; // Assume the first element is the smallest
		for (j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min_idx]) // Find the minimum element
			{
				min_idx = j;
			}
		}
		if (min_idx != i) // Swap if needed
		{
			swap(&arr[min_idx], &arr[i]);
		}
	}
	// Display sorted array
	printf("\n--------------------------------------");
	printf("\nSorted array is: ");
	for (int k = 0; k < size; k++)
	{
		printf("%d ", arr[k]);
	}
	printf("\n");
	printf("--------------------------------------\n");
}

// Swap function to exchange two elements
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Insertion sort implementation
void insertionSort(int arr[], int size)
{
	int key, i, j, k;
	for (i = 1; i < size; i++)
	{
		key = arr[i]; // Element to be positioned
		j = i - 1;
		while (j >= 0 && arr[j] > key) // Shift larger elements right
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key; // Place key in correct position
	}
	// Display sorted array
	printf("\n--------------------------------------");
	printf("\nSorted array is: ");
	for (k = 0; k < size; k++)
	{
		printf("%d ", arr[k]);
	}
	printf("\n");
	printf("--------------------------------------\n");
}
