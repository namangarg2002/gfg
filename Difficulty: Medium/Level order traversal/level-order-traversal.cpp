/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        vector<int> ans;
        
        
        if(root == NULL) return ans;
        
        queue<Node* >q;
        q.push(root);
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            ans.push_back(front->data);
            
            if(front->left){
                q.push(front->left);
            }
            
            if(front->right){
                q.push(front->right);
            }
        }
        
        return ans;
        
    }
};