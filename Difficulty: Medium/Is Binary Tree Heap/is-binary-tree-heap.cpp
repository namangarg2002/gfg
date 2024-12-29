//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
// Method 1: Solutuion

// class Info {
// public:
// 	int maxVal;
// 	bool isHeap;
// 	Info(int a, bool b) {
// 		this->maxVal = a;
// 		this->isHeap = b;
// 	}
// };

// Info checkMaxHeap(Node* root) {
// 	// base Case
// 	if(root == NULL) {
// 		return Info(INT_MIN, true);
// 	}
// 	if(root->left == NULL && root->right == NULL) {
// 		return Info(root->data, true);
// 	}
// 	Info leftAns = checkMaxHeap(root->left);
// 	Info rightAns = checkMaxHeap(root->right);
// 	// 1 case solve karna hai
// 	if(root->data > leftAns.maxVal && root->data > rightAns.maxVal && leftAns.isHeap && rightAns.isHeap) {
// 		return Info(root->data, true);
// 	}
// 	else {
// 		return Info(max(root->data, max(leftAns.maxVal, rightAns.maxVal)), false);
// 	}
// }

class Solution {
  public:
    int nodeCount(struct Node* root){
        if(!root) return 0;
        int l = nodeCount(root->left);
        int r = nodeCount(root->right);
        return 1 + (l + r);
    }
    bool isCBT(struct Node* root, int i,int &n){
        if(!root) return true;
        if(i > n) return false;
        
        return isCBT(root->left, 2*i, n) && isCBT(root->right, 2*i+1, n);
    }
    bool isMaxOrder(struct Node* root){
        if(!root) return true;
        
        
        if(root->left && root->data <= root->left->data) return false;
        if(root->right && root->data <= root->right->data) return false;
        
        return isMaxOrder(root->left) && isMaxOrder(root->right);
        
    }
    
    
    bool isHeap(struct Node* tree) {
        // Method 1 result call
        // return checkMaxHeap(tree).isHeap;
        
        // Method 2:
        int n = nodeCount(tree);
        int i=1;
        return isCBT(tree, i, n) && isMaxOrder(tree);
        
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends