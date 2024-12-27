//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range

#include <bits/stdc++.h>
using namespace std;
#define N 1000

class Solution{
    public:
    struct Info{
        int data;
        int rowIndex;
        int colIndex;
        Info(int val, int rIndex, int cIndex) : data(val), rowIndex(rIndex), colIndex(cIndex) {}
    };
    struct compare{
        bool operator()(Info* a, Info* b){
            return a->data > b->data;
        }
    };
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        priority_queue<Info*, vector<Info*>, compare>pq;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int i=0; i<k; i++){
            int element = KSortedArray[i][0];
            int row = i;
            int col = 0;
            
            Info* temp = new Info(element, row, col);
            pq.push(temp);
            maxi = max(maxi, element);
            mini = min(mini, element);
        }
        int ansStart = mini;
        int ansEnd = maxi;
        while(!pq.empty()){
            Info* topNode = pq.top();
            pq.pop();
            
            int topData = topNode->data;
            int topRow = topNode->rowIndex;
            int topCol = topNode->colIndex;
            
            mini = topData;
            
            if((maxi-mini) < (ansEnd-ansStart)){
                ansStart = mini;
                ansEnd = maxi;
            }
            
            if(topCol + 1 < n){
                int newElement = KSortedArray[topRow][topCol + 1];
                Info* newInfo = new Info(newElement, topRow, topCol + 1);
                pq.push(newInfo);
                maxi = max(maxi, newElement);
            }else{
                break;
            }
        }
        return {ansStart,ansEnd};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    
cout << "~" << "\n";
}   
	return 0;
}


// } Driver Code Ends