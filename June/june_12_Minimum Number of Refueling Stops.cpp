class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int pre=0;
        int ans=0;
        for(auto it:stations)
        {
            while((startFuel-it[0]+pre)<0)
            {
                if(pq.empty())
                    return -1;
                startFuel+=pq.top();
                pq.pop();
                ans++;
            }
            pq.push(it[1]);
            startFuel-=(it[0]-pre);
            pre=it[0];
        }
            while((startFuel-target+pre)<0)
            {
                if(pq.empty())
                    return -1;
                startFuel+=pq.top();
                pq.pop();
                ans++;
            }
        return ans;
    }
};