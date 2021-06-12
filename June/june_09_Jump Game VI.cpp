class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int dp[nums.size()];
        dp[0]=nums[0];
        priority_queue<pair<int,int>> pq;
        pq.push(make_pair(dp[0],0));
        for(int i=1;i<nums.size();i++)
        {
            while(!pq.empty())
            {
                if(pq.top().second<max(0,i-k))
                {
                    pq.pop();
                }
                else
                {
                    dp[i]=(pq.top().first)+nums[i];
                    break;
                }
            }
            pq.push(make_pair(dp[i],i));
        }
        return dp[nums.size()-1];
    }
};