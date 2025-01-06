//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        if (arr.size() < 2) return {}; // If there are less than 2 elements, return an empty vector
    
        sort(arr.begin(), arr.end());  // Sort the array
        int closestSum = INT_MAX;      // To store the closest sum
        int diff = INT_MAX;            // To store the smallest difference
        int left = 0, right = arr.size() - 1;
        pair<int, int> result;         // To store the pair with the closest sum
    
        while (left < right) {
            int currentSum = arr[left] + arr[right];
            int currentDiff = abs(currentSum - target);
    
            // If we find a closer sum, update the closest pair
            if (currentDiff < diff) {
                diff = currentDiff;
                closestSum = currentSum;
                result = {arr[left], arr[right]};
            }
    
            // Move the pointers based on the current sum comparison with the target
            if (currentSum < target) {
                left++;
            } else {
                right--;
            }
        }
    
        // Return the pair with the closest sum, or an empty vector if no pair is found
        if (closestSum == INT_MAX) {
            return {};  // No valid pair found
        }
        
        return {result.first, result.second};
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends