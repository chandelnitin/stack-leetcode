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
        
        if(cost>k) return INT_MIN;  // agr ye yhha na ho to out of bund ho jayega dp me cost
        
        if(dp[i][j][cost]!=-1) return dp[i][j][cost];  // old cost ke liye agr value nhi mili to old cost ke liye
                                                        // hi store krenge
       int newCost=cost+ ((grid[i][j]==0)?0:1);
       int right=grid[i][j]+fun(i,j+1,grid,k,newCost,dp);
       int down= grid[i][j]+ fun(i+1,j,grid,k,newCost,dp);

       return dp[i][j][cost]= max(right,down); // old cost ke liye hi store kri value
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k + 1, -1) ));
        int res=fun(0,0,grid,k,0,dp);
        if(res<0) return -1;
        return res;
    }
};