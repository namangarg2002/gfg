class Solution {
  public:
    bool checkCompressed(string &s, string &t) {
        int i = 0;
        int j = 0;
        string temp = "";
        while(j<t.size()){
            if(isalpha(t[j])){
                if(i >= s.size() || s[i] != t[j]){
                    return false;
                }
                
                i++;
                j++;
            }else{
                int num = 0;
                while(j<t.size() && isdigit(t[j])){
                    num = num * 10 + (t[j] - '0');
                    j++;
                }
                
                i += num;
                
                if (i > s.size()){
                    return false;
                }
            }
        }
        
        return i == s.size();
        
    }
};
