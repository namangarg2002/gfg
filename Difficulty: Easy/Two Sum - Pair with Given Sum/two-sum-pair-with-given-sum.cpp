//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // sort(arr.begin(), arr.end());
        
        // int s = 0;
        // int e = arr.size()-1;
        // while(s<=e){
        //     int csum = arr[s]+arr[e];
        //     if(csum==target){
        //         return true;
        //     }else if(csum > target){
        //         e--;
        //     }else{
        //         s++;
        //     }
        // }
        // return false;
        
        // or
        
        unordered_set<int>mp;
        for(int num:arr){
            int rem = target - num;
            if(mp.count(rem)){
                return true;
            }
            mp.insert(num);
        }
        
        return false;
    }
        
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends