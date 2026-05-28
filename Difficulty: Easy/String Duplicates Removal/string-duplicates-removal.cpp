// User function template for C++
class Solution {
  public:
    string removeDuplicates(string &s) {
        
        unordered_map<char, bool> mp;
        string ans = "";
        
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(mp[ch] == false){
                mp[ch] = true;
                ans.push_back(ch);
            }
        }
        
        return ans;
        
    }
};