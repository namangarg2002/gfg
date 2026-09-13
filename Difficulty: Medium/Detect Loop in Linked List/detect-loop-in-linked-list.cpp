/* Linked List Node Structure
class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
} */

class Solution {
  public:
    bool detectLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            
            if(slow == fast){
                break;
            }
        }
        
        if(fast == NULL){
            return false;
        }
        
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
        
    }
};