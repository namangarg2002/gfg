class Solution {
  public:
    void insertAtBottom(stack<int> &st, int element){
        if(st.empty()){
            st.push(element);
            return;
        }
        int temp = st.top();
        st.pop();
        insertAtBottom(st, element);
        st.push(temp);
    }
    void reverseStack(stack<int> &st) {
        if(st.empty()){
            return;
        }
        int element = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, element);
        
    }
};