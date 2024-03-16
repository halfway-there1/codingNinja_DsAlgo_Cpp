#include <iostream>
using namespace std;

void arrayInput(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void merge(int arr1[], int arr2[], int n, int m, int arr3[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            arr3[k] = arr1[i];
            i++;
        } else {
            arr3[k] = arr2[j];
            j++;
        }
        
        k++;
    }
    
    while (i < n) arr3[k++] = arr1[i++];
    
    while (j < m) arr3[k++] = arr2[j++];
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