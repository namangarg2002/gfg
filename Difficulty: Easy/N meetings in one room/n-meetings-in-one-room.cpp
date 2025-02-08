//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    struct Compare{
        bool operator()(const pair<int,int>&a, const pair<int,int>&b){
            return a.second > b.second;
        }
    };
  public:
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        int prevEnd = -1;
        int count = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare>minHeap;
        
        for(int i=0; i<n; i++){
            minHeap.push({start[i], end[i]});
        }
        while(!minHeap.empty()){
            pair<int, int> top = minHeap.top();
            minHeap.pop();
            int currStart = top.first;
            int currEnd = top.second;
            if(prevEnd < currStart){
                count++;
                prevEnd = currEnd;
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
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends