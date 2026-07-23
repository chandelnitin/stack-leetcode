class Solution {
public:
    int fun(int i,int &amount,vector<int>&coins,int collectAmount,vector<vector<int>>&dp){
        if(amount==collectAmount) return 1;
        if(collectAmount>amount) return 0;
        if(i==coins.size()) return 0;
        if(dp[i][collectAmount]!=-1) return dp[i][collectAmount];
        //pick

        int pick=fun(i,amount,coins,collectAmount+coins[i],dp);
        int notpick=fun(i+1,amount,coins,collectAmount,dp);

        return dp[i][collectAmount]= pick+notpick;

    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount,-1));
        return fun(0,amount,coins,0,dp);
    }
};