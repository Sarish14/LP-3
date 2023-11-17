//============================================================================
// Name        : LP3_Assignment-05.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int low, int high, int &counter) {
    int pivot = arr[high];
    int i = low - 1;  // Index of smaller element, Indicates the right position of pivot found so far
    for (int j = low; j < high; j++) {
        counter++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);    // this is needed when we have element greater than pivot present
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int *arr, int low, int high, int &counter) {
    if (low < high) {
        int q = partition(arr, low, high, counter);
        quickSort(arr, low, q - 1, counter);
        quickSort(arr, q + 1, high, counter);
    }
}

int randomPartition(int *arr, int low, int high, int &counter) {
	int ri = low + rand() % (high - low + 1);        // rand()generates a random number in range 0 to RAND_MAX but we need a number between 0 and len(arr) so we do % (high-low+1)
	int pivot = arr[ri];
	int i = low - 1;
	swap(arr[ri], arr[high]);               //  reason behind this swap is to treat the selected pivot as if it were the last element in the array
	for (int j = low; j < high; j++)
	{
		counter++;
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}

void randomizedQuickSort(int *arr, int p, int r, int &counter) {
    if (p < r) {
        int q = randomPartition(arr, p, r, counter);
        randomizedQuickSort(arr, p, q - 1, counter);
        randomizedQuickSort(arr, q + 1, r, counter);
    }
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    while (!(cin >> n) || n <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int A[n], B[n];
    srand(time(0));

    cout << "Enter " << n << " integers for the array:" << endl;
    for (int i = 0; i < n; ++i) {
        while (!(cin >> A[i])) {
            cout << "Invalid input. Please enter integers: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        B[i] = A[i];
    }

    int counter_quick = 0;
    int counter_randomized = 0;

    quickSort(A, 0, n - 1, counter_quick);
    cout << "Sorted array using Quick Sort: ";
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << '\n';
    cout << "Number of steps for Quick Sort: " << counter_quick << endl;

    randomizedQuickSort(B, 0, n - 1, counter_randomized);
    cout << "Sorted array using Randomized Quick Sort: ";
    for (int i = 0; i < n; ++i) {
        cout << B[i] << " ";
    }
    cout << '\n';
    cout << "Number of steps for Randomized Quick Sort: " << counter_randomized << endl;

    return 0;
}


/*

	Time Complexity:  Average - O(n*log(n))
					  Best - O(n^2) - for randomized quicksort, probability of worst case is less

	(space complexity is recursion stack space)
	Space Complexity: Average - O(log(n)) - if pivot is chosen at random
					  Worst - O(n)
 */










