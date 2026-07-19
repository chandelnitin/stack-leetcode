class Solution {
public:
    int fun1(int idx ,vector<int>&nums,vector<int>&dp1){
        if(idx==1) return nums[idx];
        if(idx==0) return 0;
        if(dp1[idx]!=-1) return dp1[idx];
        int notpick= 0+fun1(idx-1,nums,dp1);
        int pick=0;
        if(idx>1)
        pick= nums[idx]+fun1(idx-2,nums,dp1);
        return dp1[idx]= max(notpick,pick);
    }
    int fun2(int idx ,vector<int>&nums,vector<int>&dp2){
        if(idx==0) return nums[idx];
        if(idx<0) return 0;
         if(dp2[idx]!=-1) return dp2[idx];
        int notpick= 0+fun2(idx-1,nums,dp2);
        int pick=0;
        if(idx>1)
        pick= nums[idx]+fun2(idx-2,nums,dp2);
        return dp2[idx]=max(notpick,pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size(); vector<int>dp1(n,-1);vector<int>dp2(n,-1);
         if(nums.size()==1) return nums[0];
         return max(fun1(n-1,nums,dp1),fun2(n-2,nums,dp2));
    }
};