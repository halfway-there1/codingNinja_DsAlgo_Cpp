#include<iostream>
#include "StackUsingArray.cpp"
using namespace std;

int main(){
    StackUsingArray s(4);
    /* s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5); */

    cout << s.isEmpty() << endl;
    s.pop();
    cout << s.top() << endl;
    return 0;
}