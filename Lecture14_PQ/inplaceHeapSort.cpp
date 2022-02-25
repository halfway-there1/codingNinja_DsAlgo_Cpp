#include <iostream>
using namespace std;

/* a utility function for swapping */
void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int removeMin(int* arr, int &heapSize) {
    int removed = arr[0];
    arr[0] = arr[heapSize-1];
    heapSize--;

    // Down-Heapify
    int parentIndex = 0;
    while (parentIndex <= heapSize-1) {
        int minIndex = parentIndex;
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = leftChildIndex + 1;

        if (rightChildIndex <= heapSize-1) {  /* Both Child Exists */
            if (arr[parentIndex] < arr[leftChildIndex] && arr[parentIndex] < arr[rightChildIndex])
                break;
            minIndex = (arr[leftChildIndex] < arr[rightChildIndex]) ? leftChildIndex : rightChildIndex;
        }
        else if (leftChildIndex > heapSize-1)  /* None of the child exists */ {
            break;
        }
        else {                                  /* only l child exists and is definitely the left one */
            if (arr[leftChildIndex] < arr[parentIndex]) {
                minIndex = leftChildIndex;
            }
            else {
                break;
            }
        }

        swap(&arr[parentIndex], &arr[minIndex]);

        parentIndex = minIndex;
    }

    return removed;
}

void heapSort(int arr[], int n) {

    // In-Place min-Heap Building by inserting the element with Up-Heapify
    int heapSize = 1;
    for (int i = 1; i < n; i++) {
        heapSize++;
        int key = arr[i];
        int keyIndex = i;

        int parentIndex = (keyIndex-1) / 2;
        while (keyIndex != 0 && arr[parentIndex] > key) {
            arr[keyIndex] = arr[parentIndex];

            keyIndex = parentIndex;
            parentIndex = (keyIndex-1) / 2;
        }

        arr[keyIndex] = key;
    }

    // removing min from the In-Place min-Heap and placing the removed min at the end of the array

    for (int i = 0; i < n; i++) {
        int removed = removeMin(arr, heapSize);  // here 'heapSize' is passed by referece
        arr[n-1-i] = removed;  // placing the removed min at the end of the array
    }
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    }

    delete[] input;
}