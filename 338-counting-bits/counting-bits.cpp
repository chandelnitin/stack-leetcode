class Solution {
public:
    
    int getBinarySum(int n,vector<int>&dp){
        if(n==0) return 0;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        if(n%2==0){
            return dp[n]=0+getBinarySum(n/2,dp);
        }else{
            return dp[n]=1+getBinarySum(n/2,dp);
        }

    }
    vector<int> countBits(int n) {
        vector<int>ans;
        vector<int>dp(n+1,-1);
        for(int i=0;i<=n;i++){
            ans.push_back(getBinarySum(i,dp));
           
        }

        return ans;
    }
};