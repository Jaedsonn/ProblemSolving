#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>
#define pb push_back

using namespace std;

bool chegou = false;

void solve(vl giros, ll n,ll grau){
    if(chegou) return;

    if(n == giros.size()){
        if(grau == 360){
            chegou = true;
            return;
        }

        if(grau == 0){
            chegou = true;
            return;
        }

        return;
    }

    solve(giros, n + 1, grau + giros[n]);
    solve(giros, n + 1, grau + -(giros[n]));
    return;
}

int main(){
    ll n; cin >> n;
    vl giros(n); for(int i = 0; i < n; i++) cin >> giros[i];
    solve(giros, 0, 0);
    if(chegou) cout << "SIM" << endl;
    else cout << "NAO" << endl;
    return 0;
}