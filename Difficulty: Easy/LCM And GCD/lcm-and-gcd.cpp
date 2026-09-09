class Solution {
  public:
    int GCD(int a, int b){
        while(b != 0){
            int c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
    int LCM(int a, int b){
        
    }
    vector<int> lcmAndGcd(int a, int b) {
        vector<int> ans;
        
        int gcd = GCD(a, b);
        
        int lcm = (a*b)/gcd;
        
        ans.push_back(lcm);
        ans.push_back(gcd);
        
        return ans;
        
    }
};