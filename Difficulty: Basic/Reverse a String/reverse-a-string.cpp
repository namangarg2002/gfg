class Solution {
  public:
    string reverseString(string& s) {
        string ans = "";
        stack<int> st;
        for(int i=0; i<s.length(); i++){
            st.push(s[i]);
        }
        
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            ans.push_back(ch);
        }
        
        return ans;
        
    }
};
