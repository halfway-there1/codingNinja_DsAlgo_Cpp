// Change in the given string itself. So no need to return or print anything
#include <iostream>
#include <cstring>
using namespace std;

const char *pi = "3.14";

void replacePi(char *input, int size) {
    if (size <= 1) {
        return;
    }
    
    if (input[0] == 'p' && input[1] == 'i') {
        memmove(input + 4, input + 2, size - 2 + 1);
        memmove(input, pi, 4);
        replacePi(input + 4, size - 2);
        return;
    }
    
    replacePi(input + 1, size - 1);
}

void replacePi(char input[]) {
    int l = strlen(input);
    replacePi(input, l);
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
