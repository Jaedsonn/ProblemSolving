#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vl>
#define pb push_back

using namespace std;


void make_set(int v, vi &parent, vi &tsize){
    parent[v] = v;
    tsize[v] = 1;
}

int find_set(int v, vi& parent){
    if(v == parent[v]){
        return v;
    }
    
    return parent[v] = find_set(parent[v], parent);
}

int union_sets(int a, int b, vi& parent, vi& tsize){
    a = find_set(a, parent);
    b = find_set(b, parent);

    if(a != b){
        if(tsize[a] < tsize[b]){
            swap(a, b);
        }

        parent[b] = a;
        tsize[a] += tsize[b];
        return tsize[a];
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vi parent(n, 1);
    vi tsize(n, 1);

    for(int i = 0; i < n; i++) make_set(i, parent, tsize);
    int componentes = n;
    int best = 1;

    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        --x;--y;

        int resultado_union = union_sets(x, y, parent, tsize);
        
        if(resultado_union > 0){
            best = max(best, resultado_union);
            componentes -= 1;
        }
        
        cout << componentes << " " << best << endl;
    }

    return 0;
}