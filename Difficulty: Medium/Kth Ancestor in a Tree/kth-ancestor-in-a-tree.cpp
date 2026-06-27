/* Definition for Node
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
    Node* findKAncestor(Node* root, int &k, int node){
        if(root == NULL){
            return NULL;
        }
        if(root->data == node) return root;
        
        Node* left = findKAncestor(root->left, k, node);
        Node* right = findKAncestor(root->right, k, node);
        
        if(left || right){
            k--;
            if(k==0) return root;
            return left ? left : right;
        }
        
        return NULL;
    }
    int kthAncestor(Node *root, int k, int node) {
        
        Node* ancestor = findKAncestor(root, k, node);
        if(k>0 || ancestor == NULL || ancestor->data == node){
            return -1;
        }
        
        return ancestor->data;
        
    }
};
