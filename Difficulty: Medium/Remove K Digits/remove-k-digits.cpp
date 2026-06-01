class Solution {
  public:
    int charToInt(char ch){
        if(ch >= '0' && ch <= '9'){
            return ch -'0';
        }
        return -1;
    }
    string removeKdig(string &s, int k) {
        stack<char> st;
        for(auto ch: s){
            while(k != 0 && !st.empty() && charToInt(ch) < charToInt(st.top())){
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans = "";
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }

        while (!ans.empty() && ans.size() > 1 && ans.back() == '0') {
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());

        return ans.empty() ? "0" : ans;
        
    }
};