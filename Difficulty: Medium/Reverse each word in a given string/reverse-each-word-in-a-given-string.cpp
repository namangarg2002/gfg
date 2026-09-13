class Solution {
  public:
    string reverseWords(string &s) {
        vector<string> words;
        string word;
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                if(!word.empty()){
                    reverse(word.begin(), word.end());
                    words.push_back(word);
                    
                    word.clear();
                }
            }else{
                word += s[i];
            }
        }
        
        if(!word.empty()) {
            reverse(word.begin(), word.end());
            words.push_back(word);
        }
        
        string ans = "";
        
        for(int i=0; i<words.size(); i++){
            ans += words[i];
            if(i+1 < words.size()){
                ans += " ";
            }
        }
        
        return ans;
        
    }
};