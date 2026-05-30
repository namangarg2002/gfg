class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> ans(n);
        stack<pair<int, int>> st;
        for(int i=0; i<n; i++){
            int currPrice = arr[i];
            int span = 1;
            while(!st.empty() && currPrice >= st.top().first){
                span += st.top().second;
                st.pop();
            }
    
            st.push({currPrice, span});
            ans[i] = span;
        }
    
        return ans;
        
    }
};