#include<iostream>
#include <climits>
using namespace std;

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;

    public :

    StackUsingArray(){
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
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
            int *newData = new int[2*capacity];
            for(int i = 0; i < capacity; i++){
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;
            capacity *= 2;
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