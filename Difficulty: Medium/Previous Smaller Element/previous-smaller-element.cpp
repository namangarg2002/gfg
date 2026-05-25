class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n);
        stack<int> st;
        st.push(-1);
        for(int i=0; i<n; i++){
            int curr = arr[i];
            while(st.top() >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(curr);
        }
        return ans;
        
    }
};