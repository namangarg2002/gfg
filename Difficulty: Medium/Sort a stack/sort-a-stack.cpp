class Solution {
  public:
    void insertSortStack(stack<int> &st, int element){
        if(st.empty() || element > st.top()){
            st.push(element);
            return;
        }
        int temp = st.top();
        st.pop();
        
        insertSortStack(st, element);
        st.push(temp);
    }
    void sortStack(stack<int> &st) {
        if(st.empty()) return;
        
        int element = st.top();
        st.pop();
        
        sortStack(st);
        
        insertSortStack(st, element);
        
    }
};
