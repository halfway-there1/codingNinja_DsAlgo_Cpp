#include <iostream>
using namespace std;

void arrayInput(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void fill(int arr3[], int arr[], int *addressUntil) {
    int i = 0;
    while (&arr[i] <= addressUntil) {
        arr3[i] = arr[i];
        i++;
    }
}

void merge(int arr1[], int arr2[], int n, int m, int arr3[]) {
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            *arr3 = arr1[i];
            i++;
        } else {
            *arr3 = arr2[j];
            j++;
        }
        arr3++;
    }
    
    if (i == n) {
        fill(arr3, &arr2[j], &arr2[m - 1]);
    } else {
        fill(arr3, &arr1[i], &arr1[n - 1]);
    }
}

int main() {
    int n, m; cin >> n >> m;
    int *arr1 = new int[n];
    int *arr2 = new int[m];
    
    arrayInput(arr1, n);
    arrayInput(arr2, m);
    
    int *arr3 = new int[n + m];
    merge(arr1, arr2, n, m, arr3);

    for (int i = 0; i < n + m; i++) {
        cout << arr3[i] << " ";
    }
    
    return 0;
}