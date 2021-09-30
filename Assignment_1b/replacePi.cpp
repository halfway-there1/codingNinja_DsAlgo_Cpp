// Change in the given string itself. So no need to return or print anything
#include <iostream>
using namespace std;

void replacePi(char* input, int size){
    if(size <= 1){
        return;
    }
    if(input[0] == 'p' && input[1] == 'i'){
        for(int i = size; i > 1; i--){
            input[i+2] = input[i];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        size = size+2;
        replacePi(input+4,size-4);
        return;
    }
    replacePi(input + 1, size -1);
}

void replacePi(char input[]) {
	// Write your code here
    int l;
    for(l = 0; input[l] != '\0'; l++);

    replacePi(input, l);
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}

