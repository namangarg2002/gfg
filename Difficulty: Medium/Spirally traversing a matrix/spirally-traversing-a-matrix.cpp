//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        vector<int>ans;
        int rows = mat.size();
        int cols = mat[0].size();
        
        int startCol = 0;
        int startRow = 0;
        int endCol = cols - 1;
        int endRow = rows - 1;
        
        int totalElement = rows * cols;
        int count = 0;
        
        while(count < totalElement){
            for(int i=startCol; i<=endCol && count<totalElement; i++){
                ans.push_back(mat[startRow][i]);
                count++;
            }
            startRow++;
            for(int i=startRow; i<=endRow && count<totalElement; i++){
                ans.push_back(mat[i][endCol]);
                count++;
            }
            endCol--;
            for(int i=endCol; i>=startCol && count<totalElement; i--){
                ans.push_back(mat[endRow][i]);
                count++;
            }
            endRow--;
            for(int i=endRow; i>=startRow && count<totalElement; i--){
                ans.push_back(mat[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends