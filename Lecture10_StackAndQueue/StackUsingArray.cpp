#include<iostream>
#include <climits>
using namespace std;

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;

    public :

    StackUsingArray(int totalSize){
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    // return the no of elements present in my stack
    int size(){
        return nextIndex;
    }
    
    bool isEmpty(){
        return nextIndex == 0;
    }

    // insert element
    void push(int element){
        if(nextIndex == capacity){
            cout << "Stack is Full" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    
    // delete element
    int pop(){
        if(nextIndex == 0){
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // return element at the top of the stack. No deletion
    int top(){
        if(nextIndex == 0){
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }

};