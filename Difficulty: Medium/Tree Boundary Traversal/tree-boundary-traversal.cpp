//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
private:
    void printLeftBoundry(Node *root, vector<int> &result)
    {
      // base case
      if (root == NULL)
        return;
      // go back when leaf node found
      if (root->left == NULL && root->right == NULL)
      {
        return;
      }
      result.push_back(root->data);
      // if it is possible to move left then go ahead but dont move in both direction i.e., left or right
      // possible to move left
      if (root->left != NULL)
      {
        printLeftBoundry(root->left, result);
      }
      else
      {
        // not possible to move left
        printLeftBoundry(root->right, result);
      }
    }
    
    void printLeafBoundry(Node *root,vector<int> &result)
    {
      if (root == NULL)
        return;
    
      if (root->left == NULL && root->right == NULL)
      {
        result.push_back(root->data);
      }
      printLeafBoundry(root->left, result);
      printLeafBoundry(root->right, result);
    }
    
    void printRightBoundry(Node *root, vector<int> &result)
    {
      if (root == NULL)
        return;
    
      if (root->left == NULL && root->right == NULL)
      {
        return;
      }
      if (root->right != NULL)
      {
        printRightBoundry(root->right, result);
      }
      else
      {
        printRightBoundry(root->left, result);
      }
      result.push_back(root->data);
    }
    
public:
    vector <int> boundary(Node *root)
    {
        vector<int> result;
        if (root == NULL)
            return result;
    
        // Add the root node to the result
        result.push_back(root->data);
    
        // Print the left boundary excluding the root and leaf nodes
        printLeftBoundry(root->left, result);
    
        // Print all the leaf nodes
        printLeafBoundry(root->left, result);
        printLeafBoundry(root->right, result);
    
        // Print the right boundary excluding the root and leaf nodes
        printRightBoundry(root->right, result);
    
        return result;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends