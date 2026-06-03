class Solution {
  public:
    string firstNonRepeating(string &s) {
        string ans = "";
        queue<char> q;
        int freq[26] = {0};
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            freq[ch - 'a']++;
            q.push(ch);
            while(!q.empty()){
                char frontCharacter = q.front();
                if(freq[frontCharacter - 'a'] > 1){
                    q.pop();
                }else{
                    ans.push_back(frontCharacter);
                    break;
                }
            }
            
            if(q.empty()){
                ans.push_back('#');
            }
        }
        
        return ans;
        
    }
};