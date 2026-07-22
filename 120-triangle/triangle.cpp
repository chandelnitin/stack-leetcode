// class Solution {
// public: // tle
//     int fun(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
//           if(i==triangle.size()-1) return triangle[i][j] ;
//           if(dp[i][j]!=-1) return dp[i][j];
//           int bottom= triangle[i][j]+ fun(i+1,j,triangle,dp);
//           int bottomright=triangle[i][j]+fun(i+1,j+1,triangle,dp);
//           return dp[i][j]=min(bottom,bottomright);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int minSum=0;
//         int n=triangle.size();
//         vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),-1));
//         return fun(0,0,triangle,dp);
        
//     }
// };













class Solution {
public: // tabulation
    int minimumTotal(vector<vector<int>>& triangle) {
        int minSum=0;
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        // base case
        for(int j=0;j<n;j++){
            dp[n-1][j]= triangle[n-1][j];
        }

         for(int i=n-2;i>=0;i--){
            for(int j= triangle[i].size()-1;j>=0;j--){
                int bottom= triangle[i][j]+ dp[i+1][j];
                int bottomright=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(bottom,bottomright);
            }
         }
        return dp[0][0];
        
    }
};