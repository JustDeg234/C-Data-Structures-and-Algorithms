#include <stdio.h> //printf()

/*
swap() purpose:
- swap two integers in memory using pointers
- no copies, modifes the original values in the array
*/

void swap(int *a, int *b) //reference to a, b
{
	int temp = *a; //stores the value at address a
	*a = *b; //replace value at address a with value at address b
	*b = temp; //put original value into b
}

/*
heapify() purpose:
- ensure the subtree rooted at index i obeys the MAX-HEAP property of node i <= value of parent
- parameters: arr[] array currently sorted, n size of heap (not always equal to arr), i index of current root node
*/

void heapify(int arr[], int n, int i)
{
	int largest = i; // assume root is largest initially (MAX HEAP)
	//array based binary tree navigation: {A, B, C, D, E, ... , N}
	int left = 2 * i + 1; // left child index 
	int right = 2 * i + 2; // right child index

	//if left child exists AND is greater than the current largest 
	if (left < n && arr[left] > arr[largest])
	{
		largest = left; //update largest to left child for max heap
	}

	//if right child exists AND is greater than the current largest
	if(right < n && arr[right] > arr[largest])
	{
		largest = right; //update largest to right child
	}

	//if largest is not the root
	if (largest != i)
	{
		//swap the root with the largest child
		swap(&arr[i], &arr[largest]); //reference to not waste registers by copy

		//recursively heapify the affected subtree to guarantee validity 
		// throughout the heap because swapping might violate the max-heap property
		heapify(arr, n, largest);
	}
}

/*
heapSort() purpose:
- sort an array in ascending order using heap sort
i) build a max heap from the input array via heapify
ii) repeatedly move max element (root) to the end
iii) reduce heap size and restore heap property
*/

void heapSort(int arr[], int n)
{
	//Step 1: Build Max Heap
	for (int i = n / 2 - 1; i>=0; i--) //leaf nodes are found if 2*i + 1 >= n, skip since already valid heap (no children)
	{
		heapify(arr, n, i); //fix heap at index i
	}
 	//Step 2: Extract Elements from Heap
	for (int i = n - 1; i>0; i--) // subarray[0, i-1] is valid max heap, subarray[i-1,n] is sorted
	{
		swap(&arr[0], &arr[i]); //move current max (root) to the end
		heapify(arr, i, 0); //new max heap of only up to i-1 in the array, restores heap property for the new reduced heap array
	}
}

/*
printArray() purpose:
- utility function to print array contents
*/

void printArray(int arr[], int n)
{
	for (int i=0; i<n; i++)
	{
		printf("%d ", arr[i]); //print each element
	}
	printf("\n"); //newline
}

/*
main() purpose:
- entry point of program
*/

int main()
{
	int arr[] = {12, 11, 13, 2, 5, 6, 7}; //sample unsorted input array
	
	int n = sizeof(arr) / sizeof(arr[0]); //total byte size / one byte = num of elements

	printf("Sample array:\n");
	printArray(arr, n);

	heapSort(arr, n); //Heap SORT

	printf("Sorted array:\n");
	printArray(arr, n);

	return 0;
}
// Heapsort has O(nlogn) guaranteed due to heap binary tree time complexity, and O(1) space complexity, recursion depth is proportional only to logn not n, but its not stabel and slower than quicksort due to cache behavior

