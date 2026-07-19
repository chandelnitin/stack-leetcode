// class Solution {
// public:
//     int fun(int idx,vector<int>&nums,vector<int>&dp){
//         if(idx==0) return nums[idx];
//         if(idx<0) return 0;
//         if(dp[idx]!=-1) return dp[idx];
//         int notake= fun(idx-1,nums,dp);
//         int take= nums[idx]+fun(idx-2,nums,dp);
//         return dp[idx]= max(take,notake);
        
//     }
//     int rob(vector<int>& nums) {
//         vector<int>dp(nums.size(),-1);
//         return fun(nums.size()-1,nums,dp);
//     }
// };









// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>1 index shifting solution<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// class Solution {
// public:
//     int fun(int idx,vector<int>&nums,vector<int>&dp){
//         if(idx==1) return nums[0];
//         if(idx==0) return 0;
//         if(dp[idx]!=-1) return dp[idx];
//         int notake= fun(idx-1,nums,dp);
//         int take= nums[idx-1]+fun(idx-2,nums,dp);
//         return dp[idx]= max(take,notake);
        
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp(n+1,-1);
//         return fun(n,nums,dp);
//     }
// };




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>tabulation <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


// class Solution {
// public:
    // int fun(int idx,vector<int>&nums,vector<int>&dp){
    //     if(idx==1) return nums[0];
    //     if(idx==0) return 0;
    //     if(dp[idx]!=-1) return dp[idx];
    //     int notake= fun(idx-1,nums,dp);
    //     int take= nums[idx-1]+fun(idx-2,nums,dp);
    //     return dp[idx]= max(take,notake);
        
    // }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp(n+1,-1);
//         dp[0]=0;  dp[1]=nums[0];

//         for(int idx=2;idx<n+1;idx++){
//             int notake= dp[idx-1];
//             int take= nums[idx-1]+dp[idx-2];
//             dp[idx]=max(notake,take);
//         }

//         return dp[n];
//     }
// };







// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>space optimization<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev2=0;  int prev1=nums[0];

        for(int idx=2;idx<n+1;idx++){
            int notake= prev1;
            int take= nums[idx-1]+prev2;
            int curr=max(notake,take);
            prev2=prev1; 
            prev1=curr;

        }

        return prev1;
    }
};
