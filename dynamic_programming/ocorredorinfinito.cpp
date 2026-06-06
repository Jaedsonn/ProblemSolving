#include <bits/stdc++.h>
#define ll long long
#define vi vector<ll>
#define vl vector<ll>
#define vii vector < vector < ll >>
#define pb push_back

using namespace std;

long long INF = 1e18;

vector<ll> bellmanFord(ll n_salas, vii &edges, ll start) {

    vector<ll> dist(n_salas + 1, INF); 
    dist[start] = 0;

    for(ll i = 0; i <= n_salas; i++) {
        
        for(auto &edge : edges) {
            ll u = edge[0];
            ll v_dest = edge[1]; 
            ll wt = edge[2];

            if(dist[u] != INF && dist[u] + wt < dist[v_dest]) {
                if(i == n_salas) {
                    return {-1};
                }
                dist[v_dest] = dist[u] + wt;
            }
        }
        
    }
    return dist;
}

int main(){
    ll n, m; 
    if (!(cin >> n >> m)) return 0;

    vii edges;
    for(ll i = 0; i < m; i++){
        ll src, dest, wt; 
        cin >> src >> dest >> wt;
        edges.push_back({src, dest, wt});
    }

    vector<ll> ans = bellmanFord(n, edges, 1);



    if( (ans.size() == 1 && ans[0] == -1) || ans[n] == INF){
        cout << "NAO" << endl;
    } else {
        cout << "SIM" << endl;
        cout << ans[n] << endl;
    }

    return 0;
}