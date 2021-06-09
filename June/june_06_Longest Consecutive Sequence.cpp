class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        set<int> s;
        for(auto it:nums)
            s.insert(it);
        int pre=(*s.begin());
        auto itr=s.begin();
        itr++;
        int ans=1,f=1;
        for(;itr!=s.end();itr++)
        {
            if(((*itr)-pre)==1)
                ans++;
            else
                ans=1;
            pre=(*itr);
            f=max(ans,f);
        }
        return f;
    }
};