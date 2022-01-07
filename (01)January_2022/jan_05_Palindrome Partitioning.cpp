class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        go(s,0,tmp,ans);
        return ans;
    }
    void go(string &s,int cur,vector<string> &tmp,vector<vector<string>> &ans)
    {
        if(s.length()<=cur)
        {
            ans.push_back(tmp);
            return;
        }
        for(int end=cur;end<s.length();end++)
        {
            if(check_palindrome(s,cur,end))
            {
                tmp.push_back(s.substr(cur,end-cur+1));
                go(s,end+1,tmp,ans);
                tmp.pop_back();
            }
        }
    }
    bool check_palindrome(string &str,int s,int e)
    {
        while(s<e)
        {
            if(str[s++]!=str[e--])
                return false;
        }
        return true;
    }
};