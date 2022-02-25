#include <iostream>
#include <vector>
using namespace std;
#include<climits>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() {
        return pq.size() == 0;
    }

    int getSize() {
        return pq.size();
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;
        
        // Up Heapify
        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        if (isEmpty()) {  /* no elements in priority queue */
            return INT_MAX;
        }

        int removed = pq[0];
        pq[0] = pq[getSize() - 1];
        pq.pop_back();

        
        // Down Heapify
        int parentIndex = 0;

        while (parentIndex <= getSize() - 1) {

            int leftChildIndex = 2 * parentIndex + 1;
            int rightChildIndex = 2 * parentIndex + 2;
            int minIndex = parentIndex;
            
            if (rightChildIndex <= getSize() - 1) {        /* both the child exist */

                if (pq[parentIndex] < pq[leftChildIndex] && pq[parentIndex] < pq[rightChildIndex]) /* parent is minimum */
                    break;
                minIndex = (pq[leftChildIndex] < pq[rightChildIndex]) ? leftChildIndex : rightChildIndex;
            }
            else if (leftChildIndex > getSize() - 1) {   /* both of the child doesn't exist  */
                break;
            }
            else {                                      /* only 1 child exist and definitely it is the leftChild  */
                if (pq[leftChildIndex] < pq[parentIndex]) {   
                    minIndex = leftChildIndex;
                }
                else {
                    break;
                }
            }

            int temp = pq[parentIndex];
            pq[parentIndex] = pq[minIndex];
            pq[minIndex] = temp;
            parentIndex = minIndex;
        }

        return removed;
    }
};



int main() {
    PriorityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}