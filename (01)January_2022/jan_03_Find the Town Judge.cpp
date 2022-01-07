class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int fr[10000]={0};
        bool trust_table[10000]={false};
        for(int i=0;i<trust.size();i++)
        {
            fr[trust[i][1]]++;
            trust_table[trust[i][0]]=true;
        }
        for(int i=1;i<=1000;i++)
        {
            if(fr[i]==n-1 && !trust_table[i])
            {
                return i;
            }
        }
        return -1;
    }
};