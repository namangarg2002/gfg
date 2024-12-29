//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    private:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if (maxHeap.size() == minHeap.size()) {
            if (maxHeap.empty() || x <= maxHeap.top()) {
                maxHeap.push(x);
            } else {
                minHeap.push(x);
            }
        }
        else if (maxHeap.size() > minHeap.size()) {
            if (x >= maxHeap.top()) {
                minHeap.push(x);
            } else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            }
        }
        else {
            if (x <= minHeap.top()) {
                maxHeap.push(x);
            } else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(x);
            }
        }
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        else {
            return minHeap.top();
        }
        
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends