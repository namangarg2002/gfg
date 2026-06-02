class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        int n = q.size();
        if(k>n) return q;
        queue<int> ans;
        stack<int> st;
        
        for(int i=0; i<k; i++){
            int firstElement = q.front();
            q.pop();
            st.push(firstElement);
        }
        
        while(!st.empty()){
            int topElement = st.top();
            st.pop();
            ans.push(topElement);
        }
        
        for(int i=0; i<n-k; i++){
            int remainigElement = q.front();
            q.pop();
            ans.push(remainigElement);
        }
        
        return ans;
    }
};