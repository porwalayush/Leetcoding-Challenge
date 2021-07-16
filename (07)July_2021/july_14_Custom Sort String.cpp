class Solution {
public:
    string customSortString(string order, string str) {
        
        int fr[26]={0};
        for(auto it:str)
            fr[it-'a']++;
        string ans;
        for(auto it:order)
        {
            while(fr[it-'a']!=0)
            {
                ans.push_back(it);
                fr[it-'a']--;
            }
        }
        for(int i=0;i<26;i++)
        {
            while(fr[i]!=0)
            {
                ans.push_back(i+'a');
                fr[i]--;
            }
        }
        return ans;
    }
};