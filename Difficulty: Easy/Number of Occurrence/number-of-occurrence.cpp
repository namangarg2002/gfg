class Solution {
  public:
    int firstOcc(vector<int>& arr, int target, int n){
        int s = 0;
        int e = n-1;
        int index = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(arr[mid] == target){
                index = mid;
                e = mid - 1;
            }else if(arr[mid] < target){
                s = mid  + 1;
            }else{
                e = mid - 1;
            }
        }
        return index;
    }
    int lastOcc(vector<int>& arr, int target, int n){
        int s = 0;
        int e = n-1;
        int index = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(arr[mid] == target){
                index = mid;
                s = mid + 1;
            }else if(arr[mid] < target){
                s = mid  + 1;
            }else{
                e = mid - 1;
            }
        }
        return index;
    }
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        
        int firstIdx = firstOcc(arr, target, n);
        int lastIdx = lastOcc(arr, target, n);
        
        return firstIdx != -1 ? lastIdx-firstIdx+1 : 0;
        
    }
};
