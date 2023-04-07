//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    int m=edges.size();
	    if(m==0)
	    return 0;
	    vector<int> dist(n,INT_MAX);
	    dist[edges[0][0]]=0;
	    int t=n-1;
	    while(t--){
	        for(auto &i:edges){
	           int x=i[0];
	           int y=i[1];
	           int z=i[2];
	           if(dist[x]!=INT_MAX && dist[y]>dist[x]+z){
	               dist[y]=dist[x]+z;
	           }
	        }
	    }
	    int ans=0;
	    for(auto &i:edges){
	           int x=i[0];
	           int y=i[1];
	           int z=i[2];
	           if(dist[x]!=INT_MAX && dist[y]>dist[x]+z){
	               dist[y]=dist[x]+z;
	               ans=1;
	           }
	        }
	        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
