/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/

class Solution {
  public:

    Node *divide(Node *head) {
        if(head == NULL || head->next == NULL) return head;
        
        Node* evenHead = NULL;
        Node* evenTail = NULL;
        Node* oddHead = NULL;
        Node* oddTail = NULL;
        
        Node* curr = head;
        while(curr){
            
            Node* nextNode = curr->next;
            curr->next = NULL;
            
            int isOdd = (curr->data) & 1;
            
            if(isOdd){
                if(oddHead == NULL){
                    oddHead = curr;
                    oddTail = curr;
                }else{
                    oddTail->next = curr;
                oddTail = curr;
                }
            }else{
                if(evenHead == NULL){
                   evenHead = curr;
                   evenTail = curr; 
                }else{
                    evenTail->next = curr;
                    evenTail = curr;
                }
            }
            
            curr = nextNode;
        }
        
        if(evenHead == NULL){
            return oddHead;
        }

        if(oddHead == NULL){
            return evenHead;
        }
        
        evenTail->next = oddHead;
        
        return evenHead;
        
    }
};