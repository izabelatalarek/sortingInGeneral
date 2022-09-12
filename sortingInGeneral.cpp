#include <iostream>
#include <algorithm>

void selectionSort(int a[], int n) {
   
    for (int j = 0; j < n - 1; j++) {

         int iMin = j;

        for (int i = j + 1; i < n; i++) {
            if (a[i] < a[iMin])
                iMin = i;

            if (iMin != j) {
                std::swap(a[j], a[iMin]);
            } 
        }    
    } 
}

void bubbleSort(int a[], int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - 1; j++)
            if (a[j] > a[j + 1])
                std::swap(a[j], a[j + 1]);
    }
}

void insertionSort(int a[], int n) {

    int currentValue, otherIndx;

    for (int i = 1; i < n; i++) {
        currentValue = a[i];
        otherIndx = i;
        while (otherIndx > 0 && currentValue < a[otherIndx - 1]) {
            a[otherIndx] = a[otherIndx - 1];
            otherIndx--;
        }
        a[otherIndx] = currentValue; 
    }
}
//merge 
void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}


void quickSort(int arr[], int l, int r) {
    if (l < r) {
        int pivot = l;
        int i = l;
        int j = r;
        while (i < j) {
            while (arr[i] <= arr[pivot] && i < r)
                i++;
            while (arr[j] > arr[pivot])
                j--;
            if (i < j) {
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[pivot], arr[j]);
        quickSort(arr, l, j - 1);
        quickSort(arr, j + 1, r);
    }
}


// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}



int main() {
    int data[] = { 20, 12, 10, 15, 2 }; 
    int n = 5;
    selectionSort(data, n); 
    bubbleSort(data, n);
}

