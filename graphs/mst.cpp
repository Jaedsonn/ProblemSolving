#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vl>
#define pb push_back

using namespace std;

vi parent(1e5);
vi tsize(1e5, 0);

struct Edge{
    int u, v, weight;
    bool operator<(const Edge& other) const{
        return weight < other.weight;
    }
};

void make_set(int v){
    parent[v] = v;
    tsize[v] = 1;
}

int find_set(int v){
    if( v == parent[v]){
        return v;
    }

    return parent[v] = find_set(parent[v]);
}

void union_set(int v, int u){
    v = find_set(v);
    u = find_set(u);

    if( v != u){
        if(tsize[v] < tsize[u]){
            swap(v, u);
        }

        parent[u] = v;
        tsize[v] += tsize[u];
    }
}

int mst(int n, vector<Edge> edges){
    int cost = 0;
    vector<Edge> result;

    for(int i = 0; i < n; i ++){
        make_set(i);
    }

    sort(edges.begin(), edges.end());

    for(Edge e: edges){
       if(find_set(e.u) != find_set(e.v)){
           union_set(e.u, e.v);
           cost += e.weight;
           result.pb(e);
       }
    }
    
    return result.size() == n-1 ? cost : -1;
}

int main(){
    int n, m; cin >> n >> m;
    vector<Edge> edges(m);

    for(int i = 0; i < m; i++){
        int u, v, weight; cin >> u >> v >> weight;
        --u; --v;
        edges[i] = {u, v, weight};
    }

    cout << mst(n, edges) << endl;

    return 0;
}

