//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // void permute(string &s, int l, int r, vector<string> &result) {
    //     if (l == r) {
    //         result.push_back(s);
    //         return;
    //     }
    //     for (int i = l; i <= r; i++) {
    //         swap(s[l], s[i]);    
    //         permute(s, l + 1, r, result); 
    //         swap(s[l], s[i]);    
    //     }
    // }
    vector<string> findPermutation(string &s) {
        vector<string> result;
        sort(s.begin(), s.end()); // Start with the lexicographically smallest permutation
        do {
            result.push_back(s);  // Store the current permutation
        } while (next_permutation(s.begin(), s.end()));
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends