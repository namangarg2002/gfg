/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    int getLength(Node* &head){
        Node* temp = head;
        int count = 0;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    int getKthFromLast(Node* head, int k) {
        
        int length = getLength(head);
        if(length < k) return -1;
        
        int nodeToBeDeleted = length - k;
        
        Node* prev = NULL;
        Node* curr = head;
        int currentIndex = 0;
        while(currentIndex < nodeToBeDeleted){
            prev = curr;
            curr = curr->next;
            currentIndex++;
        }
        return curr->data;
        
        
    }
};