class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> freq; // sum -> count
        
        freq[0] = 1;
        int prefixSum = 0;
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            prefixSum += arr[i];
            int isAvailable = prefixSum - k;
            ans += freq[isAvailable];
            freq[prefixSum]++;
        }
        
        return ans;
        
    }
};