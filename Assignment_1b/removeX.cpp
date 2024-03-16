// Change in the given string itself. So no need to return or print anything
#include <iostream>
#include <cstring>
using namespace std;

void removeX(char *input, int size) {
    if (size < 1) return;
    
    if (input[0] == 'x') {
        memmove(input, input + 1, size - 1 + 1);
        removeX(input, size - 1);
        return;
    }
    
    removeX(input + 1, size - 1);
}

void removeX(char input[]) {
    int l = strlen(input);
    removeX(input, l);
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    removeX(input);
    cout << input << endl;
}
