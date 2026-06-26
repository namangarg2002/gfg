/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution {
  public:
    bool solve(Node *root, int target, int sum){
        if(root == NULL) return false;
        
        sum += root->data;
        if(root->left == NULL && root->right == NULL){
            if(sum == target){
                return true;
            }else{
                return false;
            }
        }
        
        bool leftAns = solve(root->left, target, sum);
        bool rightAns = solve(root->right, target, sum);
        
        return leftAns || rightAns;
    }
    bool hasPathSum(Node *root, int target) {
        int sum = 0;
        bool ans = solve(root, target, sum);
        
        return ans;
        
    }
};