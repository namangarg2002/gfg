class Solution {
  public:
    bool search(vector<int>& arr, int key) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
    
            if(arr[mid] == key) return true;
    
            if(arr[s] == arr[mid] && arr[mid] == arr[e]){
                s++;
                e--;
                continue;
            }
    
            // left Sorted Half
            if(arr[s] <= arr[mid]){
                if(arr[s] <= key && key <= arr[mid]){
                    e = mid - 1;
                }else{
                    s = mid + 1;
                }
            }
            // right sorted half
            else{
                if(arr[mid] <= key && key <= arr[e]){
                    s = mid + 1;
                }else{
                    e = mid - 1;
                }
            }
        }
    
        return false;
        
    }
};