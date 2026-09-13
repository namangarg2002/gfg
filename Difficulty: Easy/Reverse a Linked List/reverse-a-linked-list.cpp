/* Structure of Linked List Node
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* dummy = NULL;
        Node* temp = head;
        while(temp != NULL){
            Node* nxtNode = temp->next;
            temp->next = dummy;
            dummy = temp;
            temp = nxtNode;
        }
        
        return dummy;
        
    }
};