class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<pair<int,int>> v;
        map<int,int> fr;
        for(auto it:arr)
        {
            fr[it]++;
        }
        for(auto it:fr)
        {
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        int sum=0,pos=0;
        while((sum+v[pos].first)<(arr.size()/2))
        {
            sum+=v[pos++].first;
        }
        return pos+1;
    }
};