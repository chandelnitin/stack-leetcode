class Solution {
public:
   int fun(int i,int n, vector<int>& nums,vector<int>& dp){
       if(i==n) return 0;
       if(dp[i]!=-1) return dp[i];
       int ans=INT_MAX;
       for(int jump=1;jump<=3;jump++){
          int next=i+jump;

          if(next<=n){
            ans=min(ans,nums[next-1]+jump*jump+fun(i+jump,n,nums,dp));
          }
       }
       return dp[i]= ans;
   }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(costs.size(),-1);
        return fun(0,n,costs,dp);
    }
};