#include <iostream>
using namespace std;
#include <vector>
#include <climits>

class PriorityQueue {
    vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
        pq.clear();
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        pq.push_back(element);
        
        int insertedChildIndex = getSize() - 1;

        while (insertedChildIndex > 0) {
            int parentIndex = (insertedChildIndex - 1) / 2;

            if (pq[parentIndex] < pq[insertedChildIndex]) {  /* inserted child is Maximum */
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[insertedChildIndex];
                pq[insertedChildIndex] = temp;
                insertedChildIndex = parentIndex;
            }
            else {   /* parent is maximum */
                break;
            }
        }
    }

    int getMax() {
        return pq[0];
    }

    int removeMax() {
        if(isEmpty()) {
            return INT_MAX;
        }

        int removed = pq[0];
        pq[0] = pq[getSize() - 1];
        pq.pop_back();
        int parentIndex = 0;

        while (parentIndex <= getSize() - 1) {
            int leftChildIndex = 2 * parentIndex + 1;
            int rightChildIndex = 2 * parentIndex + 2;
            int maxIndex = parentIndex;

            if (rightChildIndex < getSize() - 1) {  /* both the child exists */
                if (pq[parentIndex] > pq[leftChildIndex] && pq[parentIndex] > pq[rightChildIndex]) { /* parent is maximum */
                    break;
                }
                maxIndex = (pq[leftChildIndex] > pq[rightChildIndex]) ? leftChildIndex : rightChildIndex;
            }
            else if (leftChildIndex > getSize() - 1) {  /* both the child does not exists */
                break;
            }
            else {  /* only 1 child exists and that definitely is the left one */
                if (pq[leftChildIndex] > pq[parentIndex]) {  /* the left is maximum */
                    maxIndex = leftChildIndex;
                }
                else {                                       /* parent is maximum */
                    break;
                }
            }
            
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[maxIndex];
            pq[maxIndex] = temp;
            parentIndex = maxIndex;
        }

        return removed;
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return pq.size() == 0;
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
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
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