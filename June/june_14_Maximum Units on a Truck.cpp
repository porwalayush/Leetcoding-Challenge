class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int,int>> pq;
        for(auto it:boxTypes)
        {
            pq.push({it[1],it[0]});
        }
        int tot=0,val=0;
        while(!pq.empty() &&tot+pq.top().second<=truckSize)
        {
            val+=(pq.top().first*pq.top().second);
            tot=tot+pq.top().second;
            pq.pop();
        }
        if(!pq.empty())
        val+=((truckSize-tot)*pq.top().first);
        return val;
    }
};