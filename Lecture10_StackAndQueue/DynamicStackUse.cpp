#include<iostream>
#include "DynamicStackUsingArray.cpp"
using namespace std;

int main(){
    StackUsingArray s;
    for(int i = 0; i < 100; i++){
        s.push(i+2);
    }
    cout << s.top() << endl;

    return 0;
}