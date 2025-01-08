//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0; // Not enough elements to form a triangle
    
        // Sort the array
        sort(arr.begin(), arr.end());
    
        int count = 0;
    
        // Fix the largest side as arr[k] and use two pointers for the other two sides
        for (int k = n - 1; k >= 2; --k) {
            int i = 0, j = k - 1;
    
            // Check pairs (arr[i], arr[j]) that satisfy the triangle condition
            while (i < j) {
                if (arr[i] + arr[j] > arr[k]) {
                    // All pairs (arr[i], arr[m]) where i <= m < j will satisfy the condition
                    count += (j - i);
                    --j; // Move the right pointer left
                } else {
                    ++i; // Move the left pointer right
                }
            }
        }
    
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends