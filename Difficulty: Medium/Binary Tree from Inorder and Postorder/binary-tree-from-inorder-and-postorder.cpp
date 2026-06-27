/* Node Structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int searchElementInorderPosition(vector<int>& inorder, int element, int size){
        for(int i=0; i<size; i++){
            if(inorder[i] == element){
                return i;
            }
        }
        return -1;
    }
    Node* createTreeFromInorderAndPostOrder(vector<int>& inorder, vector<int>& postorder, int &postorderIndex, int inorderStart, int inorderEnd, int size){
        if(postorderIndex < 0 || inorderStart > inorderEnd){
            return NULL;
        }
        int element = postorder[postorderIndex];
        postorderIndex--;
        Node* root = new Node(element);
        int position = searchElementInorderPosition(inorder, element, size);

        root->right = createTreeFromInorderAndPostOrder(inorder, postorder, postorderIndex, position+1, inorderEnd, size);
        root->left = createTreeFromInorderAndPostOrder(inorder, postorder, postorderIndex, inorderStart, position-1, size);

        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int size = inorder.size();
        int postorderIndex = size-1;
        Node* root = createTreeFromInorderAndPostOrder(inorder, postorder, postorderIndex, 0, size-1, size);

        return root;
        
    }
};