#include <iostream>
using namespace std;

int k = 0;
void printSubsetsOfArray(int input[], int n, int curr_subset[], int idx) {
    if (idx == n) {
        for (int i = 0; i < k; i++) {
            cout << curr_subset[i] << " ";
        }
        cout << endl;
        
        return;
    }
    
    printSubsetsOfArray(input, n, curr_subset, idx + 1);
    
    curr_subset[k++] = input[idx];
    printSubsetsOfArray(input, n, curr_subset, idx + 1);
    k--;
}

void printSubsetsOfArray(int input[], int size) {
    int output[10] = {0};
    printSubsetsOfArray(input, size, output, 0);
}

int main() {
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
}
