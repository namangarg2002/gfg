class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int ans = 1e9;
        int index = -1;
    
        while(s<=e){
            int mid = s + (e-s)/2;
    
            if(arr[s] <= arr[e]){
                if(arr[s] < ans){
                    ans = arr[s];
                    index = s;
                }
                break;
            }
    
            else if(arr[s] <= arr[mid]){
                if(arr[s] < ans){
                    ans = arr[s];
                    index = s;
                }
                s = mid + 1;
            }else{
                if(arr[mid] < ans){
                    ans = arr[mid];
                    index = mid;
                }
                e = mid - 1;
            }
        }
        return index;
        
    }
};
