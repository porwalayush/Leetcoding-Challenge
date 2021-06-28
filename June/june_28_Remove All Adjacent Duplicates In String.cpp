class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        for(auto it:s)
        {
            char sec=(!st.empty())?st.top():'1';
            st.push(it);
            if(sec==it)
            {
                st.pop();
                st.pop();
            }
        }
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};