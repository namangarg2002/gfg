/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    pair<int, bool> solve(Node* root){
        if(root == NULL){
            return {0, true};
        }
    
        pair<int, bool> left = solve(root->left);
        pair<int, bool> right = solve(root->right);
    
        bool isLeftBalanced = left.second;
        bool isRightBalnced = right.second;
    
        int leftHeight = left.first;
        int rightHeight = right.first;
    
        int height = 1 + max(leftHeight, rightHeight);
    
        bool currBalanced = abs(leftHeight - rightHeight) <= 1;
    
    
        bool isBalanced = isLeftBalanced && isRightBalnced && currBalanced;
    
        return {height, isBalanced};
    }
    bool isBalanced(Node* root) {
        return solve(root).second;
        
    }
};