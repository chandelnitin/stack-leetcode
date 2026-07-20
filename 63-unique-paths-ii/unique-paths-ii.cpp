class Solution {
public:
     int fun(int i,int j ,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]) return 0;
        if(i==obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1 && obstacleGrid[i][j] ==0) return 1;
        if(i>=obstacleGrid.size()|| j>=obstacleGrid[0].size()) return 0;
        if(obstacleGrid[i][j] ==1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=fun(i+1,j,obstacleGrid,dp)+fun(i,j+1,obstacleGrid,dp);
        
     }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return fun(0,0,obstacleGrid,dp);
    }
};