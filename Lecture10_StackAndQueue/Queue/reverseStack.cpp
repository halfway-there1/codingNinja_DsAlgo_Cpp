#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    if (input.empty() || input.size() == 1) {
        return;
    }
    int x = input.top();
    input.pop();
    reverseStack(input,extra); // <-- this line is the smallProblem
    while (!input.empty()) {
        extra.push(input.top());
        input.pop();
    }
    input.push(x);
    while (!extra.empty()) {
        input.push(extra.top());
        extra.pop();
    }
    return;
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}