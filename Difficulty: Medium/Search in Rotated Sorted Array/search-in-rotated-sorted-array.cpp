class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int s = 0;
        int e = arr.size()-1;
        
        while(s <= e){
            int mid = s + (e-s)/2;
            
            if(arr[mid] == key){
                return mid;
            }
            
            // left side sorted
            if(arr[s] <= arr[mid]){
                if(arr[s] <= key && key < arr[mid]){
                    e = mid - 1;
                }else{
                    s = mid + 1;
                }
            }else{
                // right side sorted
                if(arr[mid] < key && key <= arr[e]){
                    s = mid + 1;
                }else{
                    e = mid - 1;
                }
            }
        }
        
        return -1;
        
    }
};