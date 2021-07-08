class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        int pre=0,mx1=1;
        for(auto it:horizontalCuts)
        {
            mx1=max((it-pre),mx1);
            pre=it;
        }
        mx1=max(h-pre,mx1);
        sort(verticalCuts.begin(),verticalCuts.end());
        pre=0;
        int mx2=1;
        for(auto it:verticalCuts)
        {
            mx2=max((it-pre),mx2);
            pre=it;
        }
        mx2=max(w-pre,mx2);
        long long mod=1000000007;
        return ((mx1%mod)*(mx2%mod))%mod;
    }
};