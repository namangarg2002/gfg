//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    // Memoization Approach
    int solveUsingMemoization(int n, int x, int y, int z, vector<int> &dp)
    {
      if (n == 0)
        return 0;
      if (n < 0)
        return INT_MIN;
    
      if (dp[n] != -1)
      {
        return dp[n];
      }
    
      int opt1 = 1 + solveUsingMemoization(n - x, x, y, z, dp);
      int opt2 = 1 + solveUsingMemoization(n - y, x, y, z, dp);
      int opt3 = 1 + solveUsingMemoization(n - z, x, y, z, dp);
    
      dp[n] = max(opt1, max(opt2, opt3));
    
      return dp[n];
    }
    
    
    // recurssive approach
    int maximizeTheCuts(int n, int x, int y, int z) {
        
        // if (n == 0){
        //     return 0;
        // }
        // if (n < 0){
            
        //     return INT_MIN;
        // }
    
        // int opt1 = 1 + maximizeTheCuts(n - x, x, y, z);
        // int opt2 = 1 + maximizeTheCuts(n - y, x, y, z);
        // int opt3 = 1 + maximizeTheCuts(n - z, x, y, z);
        
        // int ans = max(opt1, max(opt2, opt3));
        // return ans;
        
        vector<int> dp(n+1, -1);
        int result = solveUsingMemoization(n, x, y, z, dp);
        
        return result < 0 ? 0 : result;
        
    }
};

//{ Driver Code Starts.
int main() {

    // taking testcases
    int t;
    cin >> t;
    while (t--) {
        // taking length of line segment
        int n;
        cin >> n;

        // taking types of segments
        int x, y, z;
        cin >> x >> y >> z;
        Solution obj;
        // calling function maximizeTheCuts()
        cout << obj.maximizeTheCuts(n, x, y, z) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends