class Solution {
public:
     int fun(int i,int j,int &n,int &m,vector<vector<int>>&dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=fun(i-1,j,m,n,dp)+fun(i,j-1,m,n,dp);
     }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
       return fun(m-1,n-1,m,n,dp);
    }
};