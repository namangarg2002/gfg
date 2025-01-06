//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Memoization Approach
    int solveUsingMemoization(int capacity, vector<int> weight, vector<int> profit, int index, int n, vector<vector<int>> &dp)
    {
      // base case
      if (index == n)
      {
        return 0;
      }
    
      if (dp[capacity][index] != -1)
      {
        return dp[capacity][index];
      }
    
      int include = 0;
      if (weight[index] <= capacity)
      {
        include = profit[index] + solveUsingMemoization(capacity - weight[index], weight, profit, index + 1, n, dp);
      }
      int exclude = 0;
      exclude = 0 + solveUsingMemoization(capacity, weight, profit, index + 1, n, dp);
    
      dp[capacity][index] = max(include, exclude);
    
      return dp[capacity][index];
    }
    
    // Tabulation approach
    int solveUsingTabulation(int capacity, vector<int> weight, vector<int> profit, int n)
    {
      // Step 1 :
      vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));
    
      // Step 2: base case analyse
      for (int row = 0; row <= capacity; row++)
      {
        dp[row][n] = 0;
      }
    
      for (int i = 0; i <= capacity; i++)
      {
        for (int j = n - 1; j >= 0; j--)
        {
          int include = 0;
          // replace capacity with i and index with k
          if (weight[j] <= i)
          {
            include = profit[j] + dp[i - weight[j]][j+1];
          }
          int exclude = 0 + dp[i][j + 1];
    
          dp[i][j] = max(include, exclude);
        }
      }
      return dp[capacity][0];
    }
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        // // Momoization approach
        // vector<vector<int>> dp(capacity + 1, vector<int>(n, -1));
        // int ans = solveUsingMemoization(capacity, wt, val, 0, n, dp);
        
        // Tabulation Approach
        int ans = solveUsingTabulation(capacity, wt, val, n);
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends