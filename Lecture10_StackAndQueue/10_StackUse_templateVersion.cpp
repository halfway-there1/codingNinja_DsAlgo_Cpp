#include <iostream>
#include <string>
#include "10_StackUsingArray_templateVersion.cpp"
using namespace std;

int main(){
    StackUsingArray<char> s;
    /* s.push('a');
    s.push('b');
    s.push('c');
    s.pop();
    cout << s.top() << endl; */
    StackUsingArray<string> str;
    str.push("Anurag");
    str.push("Purnima");
    cout << str.pop() << " " << str.top() << endl;
    return 0;
}