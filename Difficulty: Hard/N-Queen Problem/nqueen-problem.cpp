//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void backtrack(vector<vector<int>>& solutions, vector<int>& board, int row, int n) {
        if (row == n) {
            // Convert to 1-based indices before storing the solution
            vector<int> formatted;
            for (int col : board) {
                formatted.push_back(col + 1); // Adjust to 1-based
            }
            solutions.push_back(formatted);
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            if (isValid(board, row, col)) {
                board[row] = col;
                backtrack(solutions, board, row + 1, n);
            }
        }
    }
    
    bool isValid(vector<int>& board, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (board[i] == col || abs(row - i) == abs(col - board[i])) {
                return false;
            }
        }
        return true;
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> solutions;
        vector<int> board(n);
        backtrack(solutions, board, 0, n);
        return solutions;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends