class Solution {
  public:
    int lowerBoundIndex(vector<int> &arr, int x){
        int s = 0;
        int e = arr.size() - 1;
        int index = arr.size();
        while(s<=e){
            int mid = s + (e-s)/2;
            if(arr[mid] >= x){
                index = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return index;
    }
    
    int UpperBoundIndex(vector<int> &arr, int x){
        int s = 0;
        int e = arr.size() - 1;
        int index = arr.size();
        while(s<=e){
            int mid = s + (e-s)/2;
            if(arr[mid] > x){
                index = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        
        return index;
    }
    int findFrequency(vector<int> arr, int x) {
        sort(arr.begin() , arr.end());
        
        int LIdx = lowerBoundIndex(arr, x);
        int UIdx = UpperBoundIndex(arr, x);
        
        
        return UIdx - LIdx;
        
    }
};