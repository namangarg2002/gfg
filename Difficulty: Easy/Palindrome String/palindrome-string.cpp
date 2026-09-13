class Solution {
  public:
    bool isPalindrome(string& s) {
        int start = 0;
        int end = s.length() -1;
        while(start<=end){
            if(s[start] != s[end]){
                return false;
            }else{
                start++;
                end--;
            }
        }
        
        return true;
        
    }
};