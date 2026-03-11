//Number of Connected Components (DFS/BFS)
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node]=true;

    for(int neigh:adj[node]) {
        if(!visited[neigh])
            dfs(neigh,adj,visited);
    }
}

int countComponents(int n, vector<pair<int,int>> edges) {

    vector<vector<int>> adj(n+1);

    for(auto e:edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    vector<bool> visited(n+1,false);
    int components=0;

    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            components++;
            dfs(i,adj,visited);
        }
    }

    return components;
}