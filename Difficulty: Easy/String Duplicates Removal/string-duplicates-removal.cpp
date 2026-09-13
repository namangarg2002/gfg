class Solution {
  public:
    string removeDuplicates(string &s) {
        unordered_map<char, int> freq;
        
        string ans = "";
        for(char ch: s){
            if(freq[ch] == 0){
                ans.push_back(ch);
                freq[ch]++;
            }
        }
        
        
        return ans;
        
    }
};