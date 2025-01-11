//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        unordered_map<char, int> charIndex; // To store the last index of each character
        int maxLength = 0;
        int start = 0; // Start index of the current substring
    
        for (int end = 0; end < s.length(); end++) {
            char currentChar = s[end];
    
            // If the character is already in the map and its index is within the current window
            if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= start) {
                // Move the start of the window to the right of the previous occurrence
                start = charIndex[currentChar] + 1;
            }
    
            // Update the last index of the current character
            charIndex[currentChar] = end;
    
            // Calculate the current window size and update maxLength
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends