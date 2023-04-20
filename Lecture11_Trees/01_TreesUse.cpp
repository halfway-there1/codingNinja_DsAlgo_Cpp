#include <iostream>
#include <queue>
#include "01_TreesNode.cpp"
using namespace std;

/* ------------------------------------------------------------------------- */

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter rootData: ";
    cin >> rootData;
    TreeNode<int>* rootNode = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(rootNode);
    while (!pendingNodes.empty()) {
        TreeNode<int>* currentNode = pendingNodes.front();
        pendingNodes.pop();
        
        cout << "Enter the number of children of " << currentNode->data << ": ";
        int numChildren;
        cin >> numChildren;
        
        for (uint32_t childIndex = 0; childIndex < numChildren; childIndex++) {
            int childData;
            cout << "Enter data for child " << childIndex << " of node " << currentNode->data << ": ";
            cin >> childData;
            
            //* childNode should not be created statically as it would
            //* be deallocated just in the next iteration
            TreeNode<int>* childNode = new TreeNode<int>(childData);
            currentNode->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }
    
    return rootNode;
}

/* ------------------------------------------------------------------------- */

// this fxn is not very good way to take i/p as this requires 
// the user to have understanding of recursion thus we another
// fxn named takeInputLevelWise() will be made above
TreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter Data:";
    cin >> rootData;
    TreeNode<int> *rootNode = new TreeNode<int>(rootData);

    int numChildren;
    cout << "Enter no of children of " << rootData << " :";
    cin >> numChildren;
    for(int childIndex = 0; childIndex < numChildren; childIndex++){
        TreeNode<int> *childNode = takeInput();
        rootNode->children.push_back(childNode);
    }
    return rootNode;
}

/* ------------------------------------------------------------------------- */

void printNode(const TreeNode<int>* node) {
    if (node == nullptr) {
        return;
    }

    cout << node->data << ": ";
    for (const auto &child : node->children) {
        cout << child->data << ", ";
    }
    cout << endl;
}

void printTree(const TreeNode<int>* rootNode) {
    // Handle the case where the tree is empty.
    // this is edge case & not base case bcoz 
    // while through recursion, recursion will never hit this case
    if (rootNode == nullptr) {
        return;
    }

    // Print the current node and its children.
    printNode(rootNode);

    // Recursively call the function on each child node.
    for (const auto &child : rootNode->children) {
        printTree(child);
    }
}
/* ------------------------------------------------------------------------- */

void printLevelWise(TreeNode<int>* rootNode) {
    if (!rootNode) {
        return;
    }
    
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(rootNode);
    while (!pendingNodes.empty()) {
        TreeNode<int>* currentNode = pendingNodes.front();
        pendingNodes.pop();
        
        cout << currentNode->data << ": ";
        for(const auto &child: currentNode->children) {
            cout << child->data << ",";
            pendingNodes.push(child);
        }
        
        cout << endl;
    }
}

/* ------------------------------------------------------------------------- */

int main() {
   /* TreeNode<int> *root = new TreeNode<int>(1);
   TreeNode<int> *node1 = new TreeNode<int>(2);
   TreeNode<int> *node2 = new TreeNode<int>(3);
   root->children.push_back(node1);
   root->children.push_back(node2);

   TreeNode<int> *root = takeInput() ;
   printTree(root); */

   TreeNode<int> *rootNode = takeInputLevelWise() ;
   printLevelWise(rootNode);
   return 0;
   
   // TODO delete the tree
}