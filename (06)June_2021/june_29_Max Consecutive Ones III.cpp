class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,mx=0,cnt=0;
        while(j<nums.size())
        {
            if(nums[j]==0)
                cnt++;
            if(cnt>k)
            {
                while(cnt!=k)
                {
                    if(nums[i]==0)
                        cnt--;
                    i++;
                }
            }
            if(cnt<=k)
                mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};