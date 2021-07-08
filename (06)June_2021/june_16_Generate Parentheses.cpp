class Solution {
public:
    vector<string> ans; 
    void solve(int n,int op,int cl,string s)
    {
        if(op==n && cl==n)
        {
            ans.push_back(s);
            return;
        }
        if(op<n)
        {
            solve(n,op+1,cl,s+"(");
        }
        if(op>cl)
        {
            solve(n,op,cl+1,s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(n,0,0,"");
        return ans;
    }
};