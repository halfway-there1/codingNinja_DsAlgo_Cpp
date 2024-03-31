#include <algorithm> // for swap() fxn
#include <iostream>
using namespace std;

int partition(int input[], int si, int ei) {
    int pivot = input[si];

    // counting how many nums are bigger than pivot
    int cnt = 0;
    for (int i = si + 1; i <= ei; i++) cnt += (pivot >= input[i]);
    
    // placing the pivot at its right index.
    int pivotIndex = si + cnt;
    swap(input[si], input[pivotIndex]);
    

    // partitioning process.
    for (int i = si, j = ei; i < pivotIndex && j > pivotIndex;) {
        if (input[i] > pivot) {
            if (input[j] <= pivot) {
                swap(input[i], input[j]);
                i++, j--;
            } else {
                j--;
            }
        } else {
            i++;
            if (input[j] > pivot) {
                j--;
            }
        }
    }

    return pivotIndex;
}

void quickSort(int input[], int si, int ei) {
    if (si >= ei) {
        return;
    }

    int pivotIndex = partition(input, si, ei);
    quickSort(input, si, pivotIndex - 1);
    quickSort(input, pivotIndex + 1, ei);
}

void quickSort(int input[], int size) {
    quickSort(input, 0, size - 1);
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quickSort(input, n);
    for (int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    delete[] input;
}

// TCA