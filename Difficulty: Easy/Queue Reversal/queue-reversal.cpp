class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        stack<int>st;
        while(!q.empty()){
            int frontElement = q.front();
            q.pop();
            st.push(frontElement);
        }
        
        while(!st.empty()){
            int topElement = st.top();
            st.pop();
            q.push(topElement);
        }
    }
};