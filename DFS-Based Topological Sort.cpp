#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st)
{
    visited[node] = true;

    for(int neighbor : adj[node])
    {
        if(!visited[neighbor])
            dfs(neighbor, adj, visited, st);
    }

    st.push(node);
}

int main()
{
    int n = 4;

    vector<vector<int>> adj(n+1);

    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(4);

    vector<bool> visited(n+1,false);
    stack<int> st;

    for(int i=1;i<=n;i++)
        if(!visited[i])
            dfs(i,adj,visited,st);

    cout<<"Topological Order (DFS): ";

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}