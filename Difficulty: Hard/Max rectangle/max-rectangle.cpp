class Solution {
  public:
    vector<int> nextSmallerIndex(vector<int> &arr){
        int n = arr.size();
        vector<int> v(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            int curr = arr[i];
            while(!st.empty() && curr <= arr[st.top()]){
                st.pop();
            }
            v[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return v;
    }
    vector<int> prevSmallerIndex(vector<int> &arr){
        int n = arr.size();
        vector<int> v(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            int curr = arr[i];
            while(!st.empty() && curr <= arr[st.top()]){
                st.pop();
            }
            v[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return v;
    }
    int largestRectangle(vector<int> &heights){
        vector<int> next = nextSmallerIndex(heights);
        vector<int> prev = prevSmallerIndex(heights);

        vector<int> area(heights.size());
        for(int i=0; i<heights.size(); i++){
            int width = next[i] - prev[i] - 1;
            int height = heights[i];

            int currArea = width * height;
            area[i] = currArea;
        }

        int maxi = INT_MIN;
        for(int i=0; i<area.size(); i++){
            maxi = max(maxi, area[i]);
        }

        return maxi;
    }
    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> height(m, 0);
        int maxTotalArea = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1){
                    height[j]++;
                }else{
                    height[j] = 0;
                }
            }
            int currentRowArea = largestRectangle(height);
            maxTotalArea = max(maxTotalArea, currentRowArea);
        }

        return maxTotalArea;
        
    }
};