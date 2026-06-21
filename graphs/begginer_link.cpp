#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vl>
#define pb push_back

using namespace std;

int main(){
    int t; cin >> t;
    
    while(t--){
        int n, u, v; cin >> n;
        vi aux(n);
        vii adj(n);
        int raiz = -1;

        for(int i = 0; i < n - 1; i++){
            cin >> u >> v;
            u--; v--;
            
            adj[u].pb(v);
            adj[v].pb(u);           
        }

        int folhas = 0;

        for(vi filhos: adj){
            if(filhos.size() == 1){
                folhas += 1;
            }
        }

        cout << ceil(folhas/2.0) << endl;
    }

    return 0;
}