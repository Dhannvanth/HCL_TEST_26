#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n = 4;

    vector<vector<int>> adj(n+1);

    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(4);

    vector<int> indegree(n+1,0);

    for(int i=1;i<=n;i++)
        for(int v:adj[i])
            indegree[v]++;

    queue<int> q;

    for(int i=1;i<=n;i++)
        if(indegree[i]==0)
            q.push(i);

    cout<<"Topological Order (BFS): ";

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        cout<<node<<" ";

        for(int v:adj[node])
        {
            indegree[v]--;

            if(indegree[v]==0)
                q.push(v);
        }
    }

    return 0;
}