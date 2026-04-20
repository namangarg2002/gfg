class Solution {
  public:
    int countStudents(vector<int>& arr, int pages, int n){
        int stud = 1;
        int pagesStudent = 0;
        for(int i=0; i<n; i++){
            if(pagesStudent + arr[i] <=pages){
                pagesStudent += arr[i];
            }
            else{
                stud++;
                pagesStudent = arr[i];
            }
        }
        return stud;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        
        if(k>n) return -1;

        int s = *max_element(arr.begin(), arr.end());
        int e = accumulate(arr.begin(), arr.end(), 0);
    
        while(s<=e){
            int mid = s + (e-s)/2;
    
            int cntStud = countStudents(arr, mid, n);
    
            if(cntStud > k){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return s;
        
    }
};