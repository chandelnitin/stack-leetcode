class Solution {
public:
    int fun(int i,int j,vector<vector<int>>&grid,int &k,int cost,vector<vector<vector<int>>>&dp){


        if(i==grid.size()-1 && j==grid[0].size()-1){
            cost+=(grid[i][j]==0)?0:1;
            if(cost>k) return INT_MIN;
            else return grid[i][j];
        }
        if(i>=grid.size()) return INT_MIN;
        if(j>=grid[0].size()) return INT_MIN;
        
        cost+= (grid[i][j]==0)?0:1;
        if(cost>k) return INT_MIN;
        if(dp[i][j][cost]!=-1) return dp[i][j][cost];
       int right=grid[i][j]+fun(i,j+1,grid,k,cost,dp);
       int down= grid[i][j]+ fun(i+1,j,grid,k,cost,dp);

       return dp[i][j][cost]= max(right,down);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k + 1, -1) ));
        int res=fun(0,0,grid,k,0,dp);
        if(res<0) return -1;
        return res;
    }
};