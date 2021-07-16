class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
       vector<int> v;
        int n=a.size();
       v.push_back(a[0]);
       for(int i=1;i<n;i++)
       {
           if(v.back()<a[i])
           {
               v.push_back(a[i]);
           }
           else
           {
               int index=lower_bound(v.begin(),v.end(),a[i])-v.begin();
               v[index]=a[i];
           }
       }
       return v.size();
    }
};