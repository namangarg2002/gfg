/*
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    int getLength(Node* &head){
        int count = 1;
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    Node* deleteNode(Node* head, int x) {
        int length = getLength(head);
        
        if(x==1){
            Node* temp = head;
            head = temp->next;
            temp->next = NULL;
            delete temp;
        }else if(x == length){
            Node* prev = NULL;
            Node* curr = head;
            while(curr->next != NULL){
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            delete curr;
            
        }else{
            Node* prev = NULL;
            Node* curr = head;
            int currIndex = 1;
            while(currIndex < x){
                prev = curr;
                curr = curr->next;
                currIndex++;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
        return head;
        
    }
};