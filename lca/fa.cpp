#include <bits/stdc++.h>

#define int long long
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vl>
#define qi queue<int>
#define ql queue<ll>
#define pll pair<ll, ll>
#define pb push_back
#define loop(b) for(int i = 0; i < b; i++)

using namespace std;

const int LOGN = 19;
const int MAXN = 500005;

vi adj[MAXN];
vii up;
vi depth;

int lg(long long k) { return 63 - __builtin_clzll(k); }

void dfs(int node, int parent) {
    up[0][node] = parent;                       
    for (int k = 1; k <= LOGN; k++) {
        int act = up[k-1][node];        
        up[k][node] = up[k-1][act]; 
    }
    for (int next : adj[node]) {
        if (next != parent) {
            depth[next] = depth[node] + 1;
            dfs(next, node);
        }
    }
}

int query(int v, int k) {
    while (k) {
        v = up[lg(k)][v];
        k -= 1LL << lg(k);                      
    }
    return v;
}  

int lca(int v, int u) {
    if (depth[v] < depth[u])                    
        swap(v, u);
    v = query(v, depth[v] - depth[u]);          
    if (v == u) return v;                       
    for (int k = LOGN; k >= 0; k--) {           
        if (up[k][v] != up[k][u]) {             
            v = up[k][v];
            u = up[k][u];
        }
    }
    return up[0][v];             
}

signed main() {
    int n, q;
    cin >> n >> q;

    up.assign(LOGN + 1, vi(n));
    depth.assign(n, 0);

    loop(n - 1) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(0, 0);

    loop(q) {
        int s, t, pos;
        cin >> s >> t >> pos;

        int l = lca(s, t);
        int dist_s_l = depth[s] - depth[l];
        int dist_t_l = depth[t] - depth[l];

        if (pos > dist_s_l + dist_t_l) {
            cout << -1 << endl;
        } else if (pos <= dist_s_l) {
            cout << query(s, pos) << endl;
        } else {
            int dist = dist_t_l - (pos - dist_s_l);
            cout << query(t, dist) << endl;
        }
    }
    return 0;
}