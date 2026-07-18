class Solution {
public:
    int fun(int idx,vector<int>& cost,int &n,vector<int>&dp){
        if(idx>=n) return 0;
        if(idx==n-1) return cost[idx];
        if(dp[idx]!=-1) return dp[idx];
        int first= cost[idx]+fun(idx+1,cost,n,dp);
        int second= cost[idx]+fun(idx+2,cost,n,dp);
        return dp[idx]= min(first,second);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size(); 
        vector<int>dp(n,-1);
        return min(fun(0,cost,n,dp),fun(1,cost,n,dp));
    }
};