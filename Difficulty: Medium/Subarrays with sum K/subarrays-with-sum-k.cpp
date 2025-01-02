//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> map; 
        int csum = 0;
        int result = 0;
        
        map[0] = 1; // whenever k==0 arises this will help in tis we make a entry in map with key 0 and its value as its occurence
        for(int i=0 ;i<n; i++){
            csum += arr[i];
            
            if(map.find(csum-k) != map.end()){ // mil gaya
                result += map[csum-k];
            }
            map[csum]++;
        }
        return result;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends