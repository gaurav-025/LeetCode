//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph
    
    bool check(int node,vector<bool>& vis,vector<bool>& s,vector<int> adj[],int parent){
        vis[node]=true;
        s[node]=true;
        
        for(auto &i:adj[node]){
            if(!vis[i]){
                if(check(i,vis,s,adj,node))
                return true;
            }
            else if(s[i] && i!=parent)
            return true;
        }
        s[node]=false;
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V,false);
        vector<bool> s(V,false);
        int parent;
        
        for(int i=0;i<V;i++){
            if(!vis[i])
            if(check(i,vis,s,adj,i))
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
