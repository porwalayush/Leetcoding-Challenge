class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
        int n=grid.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        pq.push({grid[0][0],0,0});
        while(!pq.empty())
        {
            vector<int> cur=pq.top();
            pq.pop();
            if(vis[cur[1]][cur[2]])
                continue;
            vis[cur[1]][cur[2]]=true;
            if(cur[1]==n-1 && cur[2]==n-1)
                return cur[0];
            for(int i=0;i<4;i++)
            {
                int gox=cur[1]+dx[i];
                int goy=cur[2]+dy[i];
                if(gox<n && goy<n && gox>=0 && goy>=0)
                {
                    vector<int> next={max(cur[0],grid[gox][goy]),gox,goy};
                    pq.push(next);
                }
            }
        }
        return -1;
    }
};