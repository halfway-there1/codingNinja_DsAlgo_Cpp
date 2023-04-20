#include <iostream>
using namespace std;
#include <vector>
#include <queue>

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printPostOrder(TreeNode<int>* root) {
    if (root == nullptr) {
        return;
    }
    for (int i = 0; i < root->children.size(); i++) {
        printPostOrder(root->children[i]);
    }
    cout << root->data << " ";
    return;
}

// 1 3 2 3 4 1 5 1 8 1 10 2 6 7 1 9 1 11 0 0 0 1 12 1 13 0  level wise
int main() {
    TreeNode<int>* root = takeInputLevelWise();
    // printTree(root);
    printPostOrder(root);
    return 0;
}