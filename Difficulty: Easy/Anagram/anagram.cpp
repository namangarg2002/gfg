class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        if(s1.length() != s2.length()) return false;
        
        unordered_map<char, int> freq; // character-> count
        for(int i=0; i<s1.length(); i++){
            char ch = s1[i];
            freq[ch]++;
        }
        
        for(int i=0; i<s2.length(); i++){
            char ch = s2[i];
            
            if(freq.find(ch) == freq.end()) {
                return false;
            }

            freq[ch]--;

            if(freq[ch] == 0) {
                freq.erase(ch);
            }
            
        }
        return true;
    }
};