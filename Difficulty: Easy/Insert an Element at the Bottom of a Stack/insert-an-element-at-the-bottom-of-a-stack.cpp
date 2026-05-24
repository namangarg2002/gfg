// User function Template for C++

class Solution {
  public:
    void insertionAtBottom(stack<int> &st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int temp = st.top();
        st.pop();
        insertionAtBottom(st, x);
        st.push(temp);
    }
    stack<int> insertAtBottom(stack<int> st, int x) {
        insertionAtBottom(st, x);
        
        return st;
    }
};