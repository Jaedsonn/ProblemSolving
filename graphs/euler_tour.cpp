#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vl>
#define pb push_back

using namespace std;

void dfs(int node, int parent, vi& entryTime, vi& exitTime, int& timer, vii& adj){
    entryTime[node] = timer++;

    for(int neighbor: adj[node]){
        if(neighbor != parent){
            dfs(neighbor, node, entryTime, exitTime, timer, adj);
        }
    }

    exitTime[node] = timer++;
}

pair<vi, vi> euler_tour(vii& adj){
    int n = adj.size();
    int timer = 0;

    vi entryTime(n, 0);
    vi exitTime(n, 0);

    dfs(0, -1, entryTime, exitTime, timer, adj);

    return { entryTime, exitTime };
}

int main(){
    vii adj(5);

    adj[0].push_back(1); adj[1].push_back(0);
    adj[0].push_back(2); adj[2].push_back(0);
    adj[1].push_back(3); adj[3].push_back(1);
    adj[2].push_back(4); adj[4].push_back(2);

    auto [entry, exit] = euler_tour(adj);

    return 0;
}