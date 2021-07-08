class Solution {
public:
    class comparator
{
public:
  bool operator()(pair<int,int> a,pair<int,int> b)
  {
        if(a.first!=b.first)
            return a.first>b.first;
        return a.second>b.second;
  }
};
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparator> pq;
        for(auto it:arr)
        {
            pq.push({abs(it-x),it});
        }
        vector<int> ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};