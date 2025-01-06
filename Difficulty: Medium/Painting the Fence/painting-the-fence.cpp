//{ Driver Code Starts
#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solveUsingRecursion(int n, int k){
        // bas case
        if(n==1) return k;
        if(n==2) return k*k;
        
        int ans = (k-1)*((solveUsingRecursion(n-1, k)) + solveUsingRecursion(n-2, k));
        
        return ans;
    }
    
    int solveUsingMemoization(int n, int k, vector<int>&dp){
        
        if(n==1) return k;
        if(n==2) return k*k;
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        dp[n] = (k-1)*((solveUsingMemoization(n-1, k, dp)) + solveUsingMemoization(n-2, k, dp));
        
        return dp[n];
        
    }
    int countWays(int n, int k) {
        // Recursive Approach
        // int ans = solveUsingRecursion(n, k);
        
        // Memoization approach
        vector<int>dp(n+1, -1);
        int ans = solveUsingMemoization(n, k, dp);
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        Solution ob;
        cout << ob.countWays(n, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends