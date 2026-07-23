// class Solution {
// public:
//     void fun(int i,vector<int>&coins,int &amount,long long collectAmount,int requiredCoins,int &ans){
//         if(amount==collectAmount)  {
//             ans=min(ans,requiredCoins);
//             return ;
//         }
//         if(requiredCoins >= ans) return;
//         if(collectAmount>amount) return ;
//         if(i==coins.size()) return ;
//          //pickup
//         fun(i,coins,amount,collectAmount+coins[i],requiredCoins+1,ans);
//         //notpickup
//         fun(i+1,coins,amount,collectAmount,requiredCoins,ans);
        
        
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int ans=INT_MAX; sort(coins.rbegin(), coins.rend()); // mandatory nhi hai bs optemization
//         fun(0,coins,amount,0,0,ans);

//        if(ans!=INT_MAX) return ans;
//        return -1;

        
//     }
// };















class Solution {
public:
    int fun(int i,vector<int>&coins,int &amount,long long collectAmount,vector<vector<int>>&dp){
        if(amount==collectAmount)  {
            return 0; // collectmount amount ke equal ho gya tha to hme koi coin ki need nhi hai
        }
        if(collectAmount>amount) return 1e9; // INT_MAX isliye nhi kr skte kuki 1 1 krke phale se value
        if(i==coins.size()) return 1e9 ;      // add hogi or hmm INT_MAX bhi add kr denge to OVER flow
         // i==coins.size pr hmne 1e9 isliye return kiya hme yhha pr koi solution nhi mila iska matlab 
        // hmm koi solution nhi bna sakte . is case me hmm 0 return nhi kr skate kuki min(pick,notpick)
        // se anseer 0 ban jayega kuki min use kiya hai. or ye notpick me hi hoga kuki pcik me agr hmne answer nhi mila to hmne allready 1E9 likha hua hai
        if(dp[i][collectAmount]!=-1) return dp[i][collectAmount];
         //pickup
       int pick=1+ fun(i,coins,amount,collectAmount+coins[i],dp);
        //notpickup
       int notpick= fun(i+1,coins,amount,collectAmount,dp);
        
        return dp[i][collectAmount]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
         vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        if(fun(0,coins,amount,0,dp)>=1e9) return -1;

         return fun(0,coins,amount,0,dp);

        
    }
};