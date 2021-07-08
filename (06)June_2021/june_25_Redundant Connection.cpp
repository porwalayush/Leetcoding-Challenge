class Solution {
private:
    vector<int> gr[1001];
    void dfs(int cur,vector<vector<int>>& edges,vector<bool> &visited,int restricted)
    {
        visited[cur]=true;
        for(auto it:gr[cur])
        {
            if(visited[it]) continue;
            if((edges[restricted][0]==cur && edges[restricted][1]==it) || (edges[restricted][0]==it && edges[restricted][1]==cur))
                continue;
            dfs(it,edges,visited,restricted);
        }
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(auto it:edges)
        {
            gr[it[0]].push_back(it[1]);
            gr[it[1]].push_back(it[0]);
        }
        for(int i=edges.size()-1;i>=0;i--)
        {
            vector<bool> visited(edges.size()+1,false);
            
            dfs(1,edges,visited,i);
            bool can=true;
            for(int i=1;i<=edges.size();i++)
            {
                if(!visited[i])
                    can=false;
            }
            if(can)
                return edges[i];
        }
        return {};
    }
};