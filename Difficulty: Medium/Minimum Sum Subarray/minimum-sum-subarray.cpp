class Solution {
  public:
    int smallestSumSubarray(vector<int>& arr) {
        int bestEnding = arr[0];
        int ans = arr[0];
        for(int i=1; i<arr.size(); i++){
            int b1 = bestEnding + arr[i];
            int b2 = arr[i];
            bestEnding = min(b1, b2);
            ans = min(ans, bestEnding);
        }
        
        return ans;
        
    }
};
