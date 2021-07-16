class Solution {
public:
    bool isIsomorphic(string s, string t) {
        bool can=true;
        unordered_map<char,char> m,rev;
        for(int i=0;i<s.length();i++)
        {
            if(m.find(s[i])!=m.end())
            {
                if(m[s[i]]!=t[i])
                    can=false;
            }
            if(rev.find(t[i])!=rev.end())
            {
                 if(rev[t[i]]!=s[i])
                    can=false;
            }
            if(m.find(s[i])==m.end())
            {
                m[s[i]]=t[i];
                rev[t[i]]=s[i];
            }
        }
        return can;
    }
};