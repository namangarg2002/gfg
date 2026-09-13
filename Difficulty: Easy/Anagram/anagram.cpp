class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        if(s1.length() != s2.length()) return false;
        
        int freq[26] = {0};
        
        for(char ch: s1){
            freq[ch-'a']++;
        }
        
        for(char ch: s2){
            freq[ch-'a']--;
            
        }
        
        for(int i=0; i<26; i++){
            if(freq[i] != 0){
                return false;
            }
        }
        
        return true;
    }
};