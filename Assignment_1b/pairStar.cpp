// Change in the given string itself. So no need to return or print anything
#include <iostream>
#include <cstring>
using namespace std;

void pairStar(char *input, int size) {
    if (size <= 1) return;
    
    if (input[0] == input[1]) {
        memmove(input + 2, input + 1, size - 1 + 1);
        input[1] = '*';
        pairStar(input + 2, size - 1);
        return;
    }
    
    pairStar(input + 1, size - 1);
}

void pairStar(char input[]) {
    int l = strlen(input);
    pairStar(input, l);
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    pairStar(input);
    cout << input << endl;
}
