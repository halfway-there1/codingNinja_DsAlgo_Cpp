#include<iostream>
using namespace std;

template <typename T>
class StackUsingArray{
    T *data;
    int nextIndex;
    int capacity;

    public :

    StackUsingArray(){
        data = new T[4];
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
    void push(T element){
        if(nextIndex == capacity){
            T *newData = new T[2*capacity];
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
    T pop(){
        if(nextIndex == 0){
            cout << "Stack is empty" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // return element at the top of the stack. No deletion
    T top(){
        if(nextIndex == 0){
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return data[nextIndex-1];
    }

};