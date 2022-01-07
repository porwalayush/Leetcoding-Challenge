class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),cmp);
        int cur=0;
        multiset<pair<int,int>> rem;
        for(int i=0;i<trips.size();i++)
        {
            cur+=trips[i][0];
            for(auto it=rem.begin();it!=rem.end();it++)
            {
                if((*it).first<=trips[i][1])
                {
                    cur-=(*it).second;
                    rem.erase(it);
                }
            }
            rem.insert(make_pair(trips[i][2],trips[i][0]));
            if(cur>capacity)
                return false;
        }
        return true;
    }
};