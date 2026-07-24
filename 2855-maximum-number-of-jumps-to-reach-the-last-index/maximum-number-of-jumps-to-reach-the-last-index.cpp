class Solution {
public:
    int fun(int idx,vector<int>& nums, int target,vector<int>&dp){
        if(idx==nums.size()-1)return 0;
        int ans=INT_MIN;
         if(dp[idx]!=-1) return dp[idx];
        for(int j=idx+1;j<nums.size();j++){
            if(abs(nums[idx]-nums[j])<=target){
                int temp= 1+fun(j,nums,target,dp);
               if (temp != INT_MIN)
               ans = max(ans, temp);
            }
        }

        return dp[idx]= ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int>dp(nums.size(),-1);
        int result= fun(0,nums,target,dp);
        if(result<=0) return -1;
        return result;
    }
};