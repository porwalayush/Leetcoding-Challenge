class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        vector<vector<int>> v(26);
        for(int i=0;i<s.length();i++)
        {
            v[s[i]-'a'].push_back(i);
        }
        int ans=0;
        for(auto word:words)
        {
            int pos=-1;
            bool can=true;
            for(auto it:word)
            {
                auto ub=upper_bound(v[it-'a'].begin(),v[it-'a'].end(),pos);
                if(ub==v[it-'a'].end())
                    can=false;
                else
                    pos=*ub;
            }
            if(can) ans++;
        }
        return ans;
    }
};