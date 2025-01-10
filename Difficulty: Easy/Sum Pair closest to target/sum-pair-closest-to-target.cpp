//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        if(arr.size() < 2) return {};
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int s = 0; 
        int e = n-1;
        int diff=INT_MAX;
        pair<int, int>ans;
        while(s<e){
            int pairSum = arr[s] + arr[e];
            if(abs(target-pairSum)<diff){
                
                diff=min(abs(target-pairSum),diff);
                ans.first=arr[s];
                ans.second=arr[e];
            }
            if(pairSum<target){
                s++;
            }else if(pairSum>target){
                e--;
            }else{
                return {arr[s], arr[e]};
            }
        }
        return {ans.first, ans.second};
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