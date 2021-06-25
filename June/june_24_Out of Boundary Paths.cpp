#define mod 1000000007
int dp[51][51][51];
class Solution {
public:
    int solve(int m, int n, int maxMove, int i, int j)
    {
        if(i==m || j==n || i<0 || j<0)
            return 1; 
        if(maxMove==0)
            return 0;
        if(dp[i][j][maxMove]!=-1)
            return dp[i][j][maxMove];
        dp[i][j][maxMove]=((solve(m,n,maxMove-1,i-1,j)+solve(m,n,maxMove-1,i,j-1))%mod+(solve(m,n,maxMove-1,i+1,j)+solve(m,n,maxMove-1,i,j+1))%mod)%mod;
        return dp[i][j][maxMove];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,maxMove,startRow,startColumn);
    }
};