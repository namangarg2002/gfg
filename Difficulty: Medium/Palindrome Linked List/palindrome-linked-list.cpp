/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    Node* findMiddleNode(Node* &head){
        if(head->next == NULL) return head;
        
        Node* slow = head;
        Node* fast = head;
        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
               fast = fast->next;
               slow = slow->next;
            }
        }
        return slow;
    }
    Node* reverseList(Node* &prev, Node* &curr){
        if(curr == NULL) return prev;
        Node* nextNode = curr->next;
        curr->next = prev;
        return reverseList(curr, nextNode);
    }
    bool compare(Node* &head1, Node* &head2){
        while(head1 != NULL && head2 != NULL){
            if(head1->data != head2->data){
                return false;
            }else{
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        return true;
    }
    bool isPalindrome(Node *head) {
        Node* middleNode = findMiddleNode(head);
        
        Node* firstList = head;
        Node* secondList = middleNode->next;
        middleNode->next = NULL;
        
        Node* prev = NULL;
        Node* curr = secondList;
        secondList = reverseList(prev, curr);
        
        return compare(firstList, secondList);
        
    }
};