class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        for(int i=0;i<time.size();i++)
        {
            time[i]=time[i]%60;
        }
        map<int,int> m;
        int ans=0;
        for(int i=0;i<time.size();i++)
        {
            ans+=m[(time[i]==0)?0:(60-time[i])];
            m[time[i]]++;
        }
        return ans;
    }
};