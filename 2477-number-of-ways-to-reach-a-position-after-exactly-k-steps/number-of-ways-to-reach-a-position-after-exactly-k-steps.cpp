class Solution {
public:
    int MOD=1e9+7;const int OFFSET = 1000;
    int fun(int startPos,int endPos,int k,vector<vector<int>>&dp){
        if(k==0 and startPos==endPos) return 1;
        if(k<0) return 0;
        // if(startPos<0) return 0;   ye consition glat hai kuki mai negative bhi ja sakta hu
        if( dp[startPos+OFFSET][k]!=-1) return dp[startPos+OFFSET][k];
        return dp[startPos+OFFSET][k]=(fun(startPos-1,endPos,k-1,dp)+fun(startPos+1,endPos,k-1,dp))%MOD;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(3001,vector<int>(k+1,-1));  
        // agr meri startpos 0 or k=1000 to mai negative 1000 and postive 1000 pr ja sakta hu to mera dp ka maximum size 2001 ho jayega . ab problem hai ki mai dp me negative index kaise store krunga . mujhe pta hai mai negative side 1000 ja sakta hu kuki k ki value 1000 hai mximum constarintes me . so mai 1000 ka offset le lunga isliye mera size dp ka ho jayega 3001
        return fun(startPos,endPos,k,dp);
    }
};