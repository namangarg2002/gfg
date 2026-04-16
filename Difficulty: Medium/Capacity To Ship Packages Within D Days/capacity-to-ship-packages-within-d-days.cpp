// User function Template for C++

class Solution {
  public:
    int daysRequiredToFillCqapacity(int arr[], int capacity, int n){
        int days = 1;
        int load = 0;
    
        for(int i=0; i<n; i++){
            if(load + arr[i] <= capacity){
                load += arr[i];
            }else{
                days++;
                load = arr[i];
            }
        }
        return days;
    
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        int s = *max_element(arr, arr + n);
        int e = accumulate(arr, arr + n, 0);
    
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
    
            int noOfDaysRequired = daysRequiredToFillCqapacity(arr, mid, n);
    
            if(noOfDaysRequired <= d){
                ans =  mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return ans;
    }
};