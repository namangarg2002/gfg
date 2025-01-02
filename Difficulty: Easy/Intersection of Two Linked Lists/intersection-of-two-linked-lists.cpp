//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x)
        : data(x)
        , next(nullptr) {}
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << '\n';
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        if (!head1 || !head2) return NULL;
        unordered_map<int, int>mp;
        
        // hash map of LL2
        Node* curr = head2;
        while(curr!=NULL){
            mp[curr->data]++;
            curr = curr->next;
        }
        
        // iterate LL1 and elemiminate elements from LL1 which is not in LL2
        Node* ILL = NULL;
        Node* it = NULL;
        curr = head1;
        while(curr!=NULL){
            if(mp.find(curr->data) != mp.end() && mp[curr->data] > 0){
                // node value presnt in LL2
                // Create a new node for the intersection list
                Node* newNode = new Node(curr->data);
                if(!ILL){
                    ILL = newNode;
                    it = ILL;
                }else{
                    it->next = newNode;
                    it = it->next;
                }
                mp[curr->data]--;
            }
            curr = curr->next;
        }
        return ILL;
    }
};

//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        int tmp;
        string input1, input2;

        getline(cin, input1);
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            Node* new_node = new Node(tmp);
            if (!head1) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2);
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            Node* new_node = new Node(tmp);
            if (!head2) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        Node* result = obj.findIntersection(head1, head2);
        printList(result);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends