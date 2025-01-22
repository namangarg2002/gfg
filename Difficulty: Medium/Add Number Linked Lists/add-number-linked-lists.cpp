//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
#include<stack>

class Solution {
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        stack<int> stack1, stack2;
        
            // Push the values of the first list into stack1
            while (num1 != nullptr) {
                stack1.push(num1->data);
                num1 = num1->next;
            }
        
            // Push the values of the second list into stack2
            while (num2 != nullptr) {
                stack2.push(num2->data);
                num2 = num2->next;
            }
        
            Node* result = nullptr;
            int carry = 0;
        
            // Add numbers from the stacks
            while (!stack1.empty() || !stack2.empty() || carry != 0) {
                int sum = carry;
        
                if (!stack1.empty()) {
                    sum += stack1.top();
                    stack1.pop();
                }
        
                if (!stack2.empty()) {
                    sum += stack2.top();
                    stack2.pop();
                }
        
                carry = sum / 10;
        
                // Create a new node for the current digit and attach it at the front
                Node* newNode = new Node(sum % 10);
                newNode->next = result;
                result = newNode;
            }
        
            // Remove leading zeros, if any
            while (result != nullptr && result->data == 0 && result->next != nullptr) {
                Node* temp = result;
                result = result->next;
                delete temp;
            }
        
            return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends