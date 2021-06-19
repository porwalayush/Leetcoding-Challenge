class Solution {
private:
    bool ispalindrome(string &str)
    {
        for(int l=0,r=str.size()-1;l<r;)
            if(str[l++]!=str[r--])
                return false;
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> m;
        vector<vector<int>> res;
        for(int i=0;i<words.size();i++)
        {
            string tmp=words[i];
            reverse(tmp.begin(),tmp.end());
            m[tmp]=i;
        }
        for(int i=0;i<words.size();i++)
        {
            string tmp=words[i];
            if(m.count("") && m[""] != i && ispalindrome(words[i]))
                res.push_back({i, m[""]});
            for(int j=1;j<=tmp.size();j++)
            {
                string left=tmp.substr(0,j);
                string right=tmp.substr(j);
                if(m.count(left) && m[left]!=i && ispalindrome(right))
                    res.push_back({i,m[left]});
                if(m.count(right) && m[right]!=i && ispalindrome(left))
                    res.push_back({m[right],i});
            }
        }
        return res;
    }
};