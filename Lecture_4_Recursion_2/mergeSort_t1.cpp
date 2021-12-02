#include <iostream>
using namespace std;

void mergeTwoSortedArrays(int arr1[],int n,int arr2[],int m,int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j]){
            arr3[k++] = arr1[i];
            i++;
        }
        else{
            arr3[k++] = arr2[j];
            j++;
        }
    }
    while(i < n){
        arr3[k++] = arr1[i];
        i++;
    }

    while(j < m){
        arr3[k++] = arr2[j];
        j++;
    }
}

void mergeSort(int input[],int size){
    if(size <= 1){
        return;
    }
    int ei = size-1;
    int mid = (0+ei)/2;

    mergeSort(input,mid-0+1);
    mergeSort(&input[mid+1],ei-(mid+1)+1);
    int* arr3 = new int[size];

    mergeTwoSortedArrays(input,mid-0+1,&input[mid+1],size-(mid-0+1),arr3);
    
    for(int i = 0; i < size; i++){
        input[i] = arr3[i];
    }
    return;
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}