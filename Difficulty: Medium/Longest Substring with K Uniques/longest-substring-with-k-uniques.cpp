class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int ans = INT_MIN;
        int low = 0;
        unordered_map<char, int> freq;
        for(int right=0; right<s.length(); right++){
            char ch = s[right];
            freq[ch]++;
            
            if(freq.size() > k){
                freq[s[low]]--;

                if(freq[s[low]] == 0)
                    freq.erase(s[low]);
        
                low++;
            }
            
            if(freq.size() == k){
                ans = max(ans, right - low + 1);
            }
        }
        
        return ans == INT_MIN ? -1 : ans;
        
    }
};