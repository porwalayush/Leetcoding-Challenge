class Solution {
public:
    int dp[1001][1001];
    int dfs(vector<int>& stones,int low,int high)
    {
        if(low==high) return 0;
        if(dp[low][high]!=-1) return dp[low][high];   
        int res=stones[high]-stones[low]-dfs(stones,low+1,high);
        res=max(res,stones[high-1]-((low>0)?stones[low-1]:0)-dfs(stones,low,high-1)); 
        // try to maximize both players score to minimize difference 
        // we don't need to consider whose turn now
        return dp[low][high]=res;
    }
    int stoneGameVII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<stones.size();i++)
            stones[i]=stones[i-1]+stones[i];
        return dfs(stones,0,stones.size()-1);
    }
};