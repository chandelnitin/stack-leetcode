class Solution {
public:
    int fun(int idx,vector<int>&nums,int n,vector<int>&dp){
        if(idx>=n-1) {
            return 0;
        }
        int ans=INT_MAX;
        if(dp[idx]!=-1) return dp[idx];
        for(int jump=1;jump<=nums[idx];jump++){
           int temp= fun(idx+jump,nums,n,dp);
           if(temp!=INT_MAX)
           ans=min(ans,temp+1);
        }

        return dp[idx]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return fun(0,nums,n,dp);
    }
};