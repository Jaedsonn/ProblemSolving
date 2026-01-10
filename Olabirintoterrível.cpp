#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector < vector < int >>>
#define pb push_back

using namespace std;

int INF = -1;

int bfs(vector<vector<int>> &adj,
                int start, int goal)
{
    vector<int> dist(adj.size(), INF);
    vector<bool> visited(adj.size(), false);
    queue<pair<int, int>> q;

    q.push(make_pair(start, 0));
    visited[start] = true;
    dist[start] = 0;

    while (!q.empty())
    {
        auto u = q.front().first;
        auto dist_u = q.front().second;
        q.pop();


        for (int v : adj[u])
        {
            if (!visited[v])
            {
                q.push(make_pair(v, dist_u + 1));
                dist[v] = dist_u + 1;
                visited[v] = true;
            }
        }
    }
    return dist[goal];
}

int main()
{
    ll n, m, ss, si;
    cin >> n >> m >> ss >> si;

    vector<vi> adj(n + 1);

    for (ll i = 0; i < m; i++)
    {
        ll sa, sb;
        cin >> sa >> sb;
        adj[sa].pb(sb);
        adj[sb].pb(sa);
    }

    int p1 = bfs(adj, 1, ss);
    int p2 = bfs(adj, ss, si);
    int p3 = bfs(adj, si, n);

    if(p1 == -1 || p2 == -1 || p3 == -1){
        cout << -1 << endl;
    } else{
        cout << p1 + p2 + p3 << endl;
    }

    return 0;
}