/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* findMid(Node* head){
        Node* fast = head;
        Node* slow = head;
        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    Node* merge(Node* left, Node* right){
        if(left == NULL) return right;
        if(right == NULL) return left;
    
        Node* ans = new Node(-1);
        Node* mptr = ans;
    
        while(left && right){
            if(left->data <= right->data){
                mptr->next = left;
                mptr = left;
                left = left->next;
            }else{
                mptr->next = right;
                mptr = right;
                right = right->next;
            }
    
            if(left){
                mptr->next = left;
            }else{
                mptr->next = right;
            }
    
        }
        return ans->next;
    }
    Node* mergeSort(Node* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
    
        Node* mid = findMid(head);
    
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
    
        left = mergeSort(left);
        right = mergeSort(right);
    
        Node* mergeLL = merge(left, right);
    
        return mergeLL;
            
    }   
};