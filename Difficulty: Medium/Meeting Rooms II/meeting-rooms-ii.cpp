class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int i=0;
        int j=0;
        
        int n = start.size();
        int m = end.size();
        
        int rooms = 0;
        int ans = 0;
        
        while( i<n && j<m){
            if(start[i] < end[j]){
                rooms++;
                i++;
            }else{
                rooms--;
                j++;
            }
            ans = max(ans, rooms);
        }
        
        return ans;
        
    }
};
