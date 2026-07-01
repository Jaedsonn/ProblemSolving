#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vl>
#define pb push_back


using namespace std;

vi toposort(const vector<vi>& graph){
    int n = graph.size();
    vi indeg(n), q;
    for(auto& li: graph) for(int x: li) indeg[x]++;

    for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
            q.push_back(i);
        }
    }

    for(int i = 0; i < n;i++){
        for(int x: graph[q[i]]){
            if(--indeg[x] == 0) q.push_back(x);
        }
    }

    return q;
}

int main(){
    int n, m; cin >> n >> m;
    vi satis(n);

    for(int i = 0; i < n; i++) cin >> satis[i];

    vii graph(n);

    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        --x;--y;
        graph[x].pb(y);
    }

    vi dp(n, 1);
    
    vi toposortado = toposort(graph);

    for(auto topo: toposortado){
        for(auto node: graph[topo]){
            if(satis[topo] < satis[node]){
                dp[node] = max(dp[node], dp[topo]+1);
            }
        }
    }

    auto res = max_element(dp.begin(), dp.end());
    cout << *res << endl; 

    return 0;
}
