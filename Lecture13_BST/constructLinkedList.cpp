#include <iostream>
#include <queue>

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

class headAndTail {
    public:
        Node<int>* head;  
        Node<int>* tail;
        headAndTail() {
            head = nullptr;
            tail = nullptr;
        }
};

headAndTail constructLL(BinaryTreeNode<int>* root) {
    if (root == nullptr) {
        headAndTail output;
        return output;
    }
    headAndTail finalLL;
    
    Node<int> *rootNode = new Node<int>(root->data);

    headAndTail leftLL = constructLL(root->left);
    if (leftLL.head != nullptr) {
        leftLL.tail->next = rootNode;
        finalLL.head = leftLL.head;
    }
    else {
        finalLL.head = rootNode;
    }

    headAndTail rightLL = constructLL(root->right);
    if (rightLL.head != nullptr) {
        rootNode->next = rightLL.head;
        finalLL.tail = rightLL.tail;
    }
    else {
        finalLL.tail = rootNode;
    }
    
    return finalLL;    
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    headAndTail output = constructLL(root);
    return output.head;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}