class Solution {
public:
    int memo[50]={0};
    
    int climbStairs(int n) {
        memo[0]=memo[1]=1;
        if(memo[n]!=0) return memo[n];
        if(n<=0) return 0; 
        memo[n]= climbStairs(n-1)+climbStairs(n-2);
        
        return memo[n];
    }
};