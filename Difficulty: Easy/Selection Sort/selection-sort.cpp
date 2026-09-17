class Solution {
  public:
    void selectionSort(vector<int> &arr) {
        int n = arr.size();
        for(int i=0; i<n-1; i++){
            int mini = arr[i];
            int smallestIndex = i;
            for(int j=i+1; j<n; j++){
                if(arr[j] < mini){
                    mini = arr[j];
                    smallestIndex = j;
                }
            }
            
            swap(arr[i],arr[smallestIndex]);
        }
        
    }
};