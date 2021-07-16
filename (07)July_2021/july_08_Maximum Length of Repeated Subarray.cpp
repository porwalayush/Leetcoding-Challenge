class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int row=nums1.size();
        int col=nums2.size();
        int dp[row+1][col+1];
        int mx=0;
        for(int i=0;i<=row;i++)
        {
            for(int j=0;j<=col;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(nums1[i-1]==nums2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=0;
                mx=max(mx,dp[i][j]);
            }
        }
        return mx;
    }
};