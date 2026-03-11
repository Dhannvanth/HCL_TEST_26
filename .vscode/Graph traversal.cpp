#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[node] = true;

    for(int neighbor : adj[node])
    {
        if(!visited[neighbor])
            dfs(neighbor, adj, visited);
    }
}

int main()
{
    int n = 5; // number of nodes

    vector<vector<int>> adj(n+1);

    // edges
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[4].push_back(5);
    adj[5].push_back(4);

    vector<bool> visited(n+1,false);

    int components = 0;

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i, adj, visited);
            components++;
        }
    }

    cout << "Connected Components: " << components;

    return 0;
}