//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int firstOccurence(vector<int>& arr, int n, int x){
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        int ans = -1;
        while(s<=e){
            if(arr[mid] == x){
                ans = mid;
                e = mid - 1;
            }else if(x > arr[mid]){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
            mid = s + (e-s)/2; 
        }
        return ans;
    }
    int lastOccurence(vector<int>& arr, int n, int x){
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        int ans = -1;
        while(s<=e){
            if(arr[mid] == x){
                ans = mid;
                s = mid + 1;
            }else if(x > arr[mid]){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
    vector<int> find(vector<int>& arr, int x) {
        int n = arr.size();
        vector<int>ans;
        int firstPositionIndex = firstOccurence(arr, n, x);
        int lastPositionIndex = lastOccurence(arr, n, x);

        ans.push_back(firstPositionIndex);
        ans.push_back(lastPositionIndex);

        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int x;
        cin >> x;
        cin.ignore();
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, x);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends