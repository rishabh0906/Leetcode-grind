class Solution {
public:
    
    int dfs(vector<int> adj[],int node,int p,unordered_set<int> &st){
        
        
        if(st.find(node)!=st.end())
            return 0;
        
        
        int ans=1;
        
        for(int u:adj[node]){
            
             if(u==p)
                 continue;
            
            ans+=dfs(adj,u,node,st);
        }
        
        return ans;
        
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> st;
        
        for(int i=0;i<restricted.size();i++){
            st.insert(restricted[i]);
        }
        
        vector<int> adj[n];
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        return dfs(adj,0,-1,st);
    }
};