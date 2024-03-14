#include <stdio.h>

// Function to perform Bubble Sort and count swaps
void bubbleSort(int arr[], int n, int swaps[]) {
  int i, j, tmp;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Swap elements
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
        swaps[j]++;
      }
    }
  }
}

// Function to perform Selection Sort and count swaps
void selectionSort(int arr[], int n, int swaps[]) {
  int i, j, minIndex, tmp;
  for (i = 0; i < n - 1; i++) {
    minIndex = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    // Swap elements
    tmp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = tmp;
    swaps[minIndex]++;
  }
}

// Function to print the swaps for each element and total swaps
void printSwaps(int arr[], int swaps[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d: %d\n", arr[i], swaps[i]);
  }

  int totalSwaps = 0;
  for (int i = 0; i < n - 1; i++) {
    totalSwaps += swaps[i];
  }
  printf("%d\n\n", totalSwaps);
}

int main() {
  int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int n1 = 9;
  int bubbleSwapsArr1[n1];
  int selectionSwapsArr1[n1];

  int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
  int n2 = 9;
  int bubbleSwapsArr2[n2];
  int selectionSwapsArr2[n2];

  // Initialize swaps arrays to zero
  for (int i = 0; i < n1; i++) {
    bubbleSwapsArr1[i] = 0;
    selectionSwapsArr1[i] = 0;
  }

  for (int i = 0; i < n2; i++) {
    bubbleSwapsArr2[i] = 0;
    selectionSwapsArr2[i] = 0;
  }

  // Bubble Sort and print swaps for both arrays
  bubbleSort(arr1, n1, bubbleSwapsArr1);
  bubbleSort(arr2, n2, bubbleSwapsArr2);

  printf("array1 bubble sort: \n");
  printSwaps(arr1, bubbleSwapsArr1, n1);

  printf("array2 bubble sort: \n");
  printSwaps(arr2, bubbleSwapsArr2, n2);

  // Reset arrays to original unsorted state
  int array1_original[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int array2_original[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

  // Selection Sort and print swaps for both arrays
  selectionSort(array1_original, n1, selectionSwapsArr1);
  selectionSort(array2_original, n2, selectionSwapsArr2);

  printf("array1 selection sort: \n");
  printSwaps(array1_original, selectionSwapsArr1, n1);

  printf("array2 selection sort: \n");
  printSwaps(array2_original, selectionSwapsArr2, n2);

  return 0;
}