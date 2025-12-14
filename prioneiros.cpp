#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll> 

using namespace std;

bool res = false;
ll contador = 1;

void solve(vl &alvos, ll alvo, ll ind){

    if(res) return;

    ll valor = alvos[ind];
    if(valor == alvo){
        res = true;
        return;
    } else{
        contador += 1;
    }

    solve(alvos, alvo, valor);
}

int main(){
    int n, k; cin >> n;
    vl a(n); for(int i = 0; i < n; i++) cin >> a[i];
    cin >> k;

    solve(a, k, k);
    
    if(contador > a.size()/2){
        cout << "N" << endl;
    } else{
        cout << "S" << endl;
    }
    return 0;
}