class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows==1)
            return ans;
        ans.push_back({1,1});
        if(numRows==2)
            return ans;
        vector<int> pre={1,1};
        for(int i=3;i<=numRows;i++)
        {
            vector<int> tmp;
            tmp.push_back(1);
            for(int i=0;i<pre.size()-1;i++)
            {
                tmp.push_back(pre[i]+pre[i+1]);
            }
            tmp.push_back(1);
            pre=tmp;
            ans.push_back(tmp);
        }
        return ans;
    }
};