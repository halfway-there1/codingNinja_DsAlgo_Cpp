#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <climits>

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
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if (root == nullptr) {
        TreeNode<int>* node = new TreeNode<int>(INT_MAX);
        return node;
    }
    TreeNode<int>* maxNode = root;
    for (int i = 0; i < root->children.size(); i++) {
        TreeNode<int>* temp = maxDataNode(root->children[i]);
        maxNode = (maxNode->data >= temp->data) ? maxNode : temp;
    }
    
    return maxNode;
}


int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << maxDataNode(root)->data << endl;
}