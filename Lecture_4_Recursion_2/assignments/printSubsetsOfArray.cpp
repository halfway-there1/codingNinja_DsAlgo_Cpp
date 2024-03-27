#include <iostream>
using namespace std;

void printSubsetsOfArray(int input[], int size, int output[]) {
    if (size <= 0) {
        for (int i = 1; i < output[0] + 1; i++) {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }

    int length = output[0];
    printSubsetsOfArray(input + 1, size - 1, output);
    output[0] = length + 1;
    output[length + 1] = input[0];
    printSubsetsOfArray(input + 1, size - 1, output);
}


void printSubsetsOfArray(int input[], int size) {
    int output[10] = {0};
    printSubsetsOfArray(input, size, output);
}

int main() {
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
}
