class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        sum=accumulate(matchsticks.begin(),matchsticks.end(),sum);
        if(matchsticks.size()<4 || sum%4) return false;
        vector<int> v(matchsticks.size(),false);
        return backtrack(matchsticks,v,sum/4,0,0,4);
    }
    bool backtrack(vector<int>& matchsticks,vector<int>& v,int target,int cur_sum,int i,int k)
    {
        if(k==1)      // we are able to find three subsets
            return true;
        if(cur_sum==target)
            return backtrack(matchsticks,v,target,0,0,k-1);
        for(int j=i;j<matchsticks.size();j++)
        {
            if(v[j] || cur_sum+matchsticks[j]>target) continue;
            v[j]=true;
            if(backtrack(matchsticks,v,target,cur_sum+matchsticks[j],j+1,k)) return true;
            v[j]=false;
        }
        return false;
    }
};