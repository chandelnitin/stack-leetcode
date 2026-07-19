class Solution {
public:
    int fun(int idx,vector<int>&nums,vector<int>&dp){
        if(idx==0) return nums[idx];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int notake= fun(idx-1,nums,dp);
        int take= nums[idx]+fun(idx-2,nums,dp);
        return dp[idx]= max(take,notake);
        
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return fun(nums.size()-1,nums,dp);
    }
};