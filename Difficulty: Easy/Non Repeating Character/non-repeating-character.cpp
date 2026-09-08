
class Solution {
  public:
    char nonRepeatingChar(string &s) {
        unordered_map<char, int> freq; // character->count
        for(char &ch: s){
            freq[ch]++;
        }
        
        for(char ch: s){
            if(freq[ch] == 1){
                return ch;
            }
        }
        
        return '$';
        
    }
};