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

/* recursive approach */
int getLeafNodeCount(TreeNode<int>* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->children.size() == 0) {
        return 1;
    }
    int count = 0;
    for (int i = 0; i < root->children.size(); i++) {
        count += getLeafNodeCount(root->children[i]);
    }
    
    return count;
}

void printLevelWise(TreeNode<int>* root) {
    if(root == nullptr) {
        return;
    }
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ": ";
        for (int i = 0; i < front->children.size(); i++) {
            cout << front->children[i]->data << ",";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

// 1 3 2 3 4 1 5 1 8 1 10 2 6 7 1 9 1 11 0 0 0 1 12 1 13 0
int main() {
    TreeNode<int>* root = takeInputLevelWise();
    // printLevelWise(root);
    cout << getLeafNodeCount(root) << endl;
}