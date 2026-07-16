class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n=nums.size();
      int MaxAnswer=1;
      vector<int>dp(n,1);
      for(int i=0;i<n;i++){
           for(int j=0;j<i;j++){
              if(nums[j]<nums[i] && 1+dp[j]>dp[i]){
                  dp[i]=dp[j]+1;
                  MaxAnswer=max(MaxAnswer,dp[i]);
              }
           }
           
        }
        
      
      return MaxAnswer; 
    }
};