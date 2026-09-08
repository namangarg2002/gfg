class Solution {
  public:
    string substring(string &s, int l, int r) {
        string ans = "";
        for(int i=l; i<r+1; i++){
            ans += s[i];
        }
        
        return ans;
    }
};