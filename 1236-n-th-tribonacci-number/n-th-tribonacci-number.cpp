class Solution {
    int fun(int n,vector<int>&dp){
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=fun(n-1,dp) +fun(n-2,dp)+fun(n-3,dp);
        
    }
public:
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return fun(n,dp);

    }
};