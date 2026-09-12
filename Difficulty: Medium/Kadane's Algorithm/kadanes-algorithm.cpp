class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int bestEnding = arr[0];
        int ans = arr[0];
        for(int i=1; i<arr.size(); i++){
            int b1 = bestEnding + arr[i];
            int b2 = arr[i];
            bestEnding = max(b1, b2);
            ans = max(ans, bestEnding);
        }
        
        return ans;
        
    }
};