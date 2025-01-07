//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        int count = 0;
    
        while (left < right) {
            int currentSum = arr[left] + arr[right];
    
            if (currentSum == target) {
                if (arr[left] == arr[right]) {
                    // Handle duplicates where both pointers point to the same value
                    int freq = right - left + 1;
                    count += (freq * (freq - 1)) / 2; // Add all combinations of pairs
                    break;
                } else {
                    // Count occurrences of duplicates
                    int leftFreq = 1, rightFreq = 1;
    
                    while (left + 1 < right && arr[left] == arr[left + 1]) {
                        ++left;
                        ++leftFreq;
                    }
    
                    while (right - 1 > left && arr[right] == arr[right - 1]) {
                        --right;
                        ++rightFreq;
                    }
    
                    count += leftFreq * rightFreq; // Multiply frequencies of left and right
                    ++left;
                    --right;
                }
            } else if (currentSum < target) {
                ++left; // Move left pointer
            } else {
                --right; // Move right pointer
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends