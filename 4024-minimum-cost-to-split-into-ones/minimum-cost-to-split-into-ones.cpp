// class Solution {
// public:
//    int fun(int n){
//       if(n==1) return 0;
//         int ans=INT_MAX;
//       for(int i=1;i<n;i++){
//           int cost= i*(n-i);
//           int temp=cost+ fun(i)+fun(n-i);
//           ans=min(ans,temp);
//       }

//       return ans;
//    }
//     int minCost(int n) {
//         return fun(n);
//     }
// };













class Solution {
public:
   int fun(int n,vector<int>&dp){
      if(n==1) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans=INT_MAX;
      for(int i=1;i<n;i++){
          int cost= i*(n-i);
          int temp=cost+ fun(i,dp)+fun(n-i,dp);
          ans=min(ans,temp);
      }

      return dp[n]=ans;
   }
    int minCost(int n) {
        vector<int>dp(n+1,-1);
        return fun(n,dp);
    }
};