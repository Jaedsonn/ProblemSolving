#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define pb push_back
#define f(l) for(int i = 0; i < l; i++)

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n; cin >> n;
    
    vl custos(n+1); 
    for(ll i = 1; i <= n; i++) cin >> custos[i];
    
    ll k; cin >> k;

    vl minimos(n+1);
    
    minimos[n] = custos[n];
    for(ll i = n - 1; i >= 1; i--){
        minimos[i] = min(custos[i], minimos[i + 1]);
    }

    vl ans(n+1, 0);
    ans[1] = k / minimos[1];
    k = k % minimos[1];

    for(ll i = 2; i <= n; i++){
        ll diff = minimos[i] - minimos[i - 1];

        if(diff == 0){
            ans[i] = ans[i - 1];
        } else{
            ll upgrades = k / diff;

            ans[i] = min(ans[i - 1], upgrades);

            k -= ans[i]*diff;
        }
    }

    for (ll i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}