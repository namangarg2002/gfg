class Solution {
  public:
    bool isPalindrome(string& s) {
        int i = 0;
        int j = s.length() - 1;
        bool ans = true;
        while(i<=j){
            if(s[i] != s[j]){
                ans = false;
            }
            i++;
            j--;
        }
        
        return ans;
        
    }
};