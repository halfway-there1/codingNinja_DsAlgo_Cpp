#include<iostream>
using namespace std;

int partition(int input [],int si,int ei){
    int pivot = input[si];
    int actual_pivotIndex = si;

    for(int i = si+1; i <= ei; i++ ){
        if(input[i] <= pivot){
            actual_pivotIndex++;
        }
    }
    input[si] = input[actual_pivotIndex];
    input[actual_pivotIndex] = pivot;

    for(int i = si, j = ei; i < actual_pivotIndex && j > actual_pivotIndex;){
        if(!(input[i] <= pivot)){
            if(!(input[j] > pivot)){
                int temp = input[i];
                input[i] = input[j];
                input[j] = temp;
                i++;
                j--;
            }
            else{
                j--;
            }
        }
        else{
            i++;
            if(input[j] > pivot){
                j--;
            }
        }
    }
    
    return actual_pivotIndex;
}

void quickSort(int input[], int si, int ei){
    if(si >= ei){
        return;
    }
    int actual_pivotIndex = partition(input,si,ei);
    quickSort(input,si,actual_pivotIndex-1);
    quickSort(input,actual_pivotIndex+1,ei);
    return;
}

void quickSort(int input[], int size){
    quickSort(input, 0, size - 1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input,n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}