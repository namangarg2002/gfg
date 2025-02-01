//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool dfs(vector<vector<char>>& mat, string& word, int index, int i, int j, vector<vector<bool>>& visited) {
        // Base case:
        if (index == word.length()) {
            return true;
        }
    
        if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || visited[i][j] || mat[i][j] != word[index]) {
            return false;
        }
    
        visited[i][j] = true;
    
        bool found = dfs(mat, word, index + 1, i + 1, j, visited) || // Down
                     dfs(mat, word, index + 1, i - 1, j, visited) || // Up
                     dfs(mat, word, index + 1, i, j + 1, visited) || // Right
                     dfs(mat, word, index + 1, i, j - 1, visited);   // Left
    
        visited[i][j] = false;
    
        return found;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n = mat.size();
        int m = mat[0].size();
    
        vector<vector<bool>> visited(n, vector<bool>(m, false));
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0] && dfs(mat, word, 0, i, j, visited)) {
                    return true;
                }
            }
        }
    
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends