class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n1 = a.size();
        int n2 = b.size();
        if(n1>n2) return kthElement(b, a, k);
        int s = max(0, k - n2);
        int e = min(k, n1);
    
        int left = k;
        int n = n1 + n2;
        while(s<=e){
            int mid1 = (s + e) >> 1;
            int mid2 = left - mid1;
    
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
    
            if(mid1 < n1) r1 = a[mid1];
            if(mid2 < n2) r2 = b[mid2];
    
            if(mid1 - 1 >= 0) l1 = a[mid1-1];
            if(mid2 - 1 >= 0) l2 = b[mid2-1];
    
            if(l1 > r2) e = mid1 - 1;
            else if(l2 > r1) s = mid1 + 1;
    
            else{
                return max(l1, l2);
            }
        }
        return 0;
        
    }
};