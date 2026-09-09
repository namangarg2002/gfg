class Solution {
  public:
    int factorial(int n) {
        if(n == 0 || n == 1) return 1;
        
        int a = 1;
        for(int i=2; i<=n; i++){
            a *= i; 
        }
        
        return a;
        
    }
};