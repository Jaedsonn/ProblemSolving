// https://codeforces.com/contest/2179/problem/B

#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>
#define pb push_back

using  namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;

    for(ll i = 0; i < t; i++){
        ll n; cin >> n;

        vector<ll> a(n, 0);
        for(ll i = 0; i < n; i++) cin >> a[i];

        // cálculo a soma sem retirar
        ll actual = 0;
        
        for(ll i = 0;i < n - 1; i++){
            actual += abs(a[i] - a[i + 1]);
        }
        
        ll diff = actual;
        // vou retirnando o max_dif_i
        for(ll max_dif_i = 0; max_dif_i < a.size(); max_dif_i++){
            ll x = abs(a[max_dif_i] - a[max_dif_i - 1]);
            ll y = abs(a[max_dif_i] - a[max_dif_i + 1]);
            
            if(max_dif_i == 0){
                diff = min(diff, abs(actual - y));
            } else if (max_dif_i == a.size() - 1){
                diff = min(diff, abs(actual - x));
            } else{
                diff = min(diff, abs(actual - (x + y)) + abs(a[max_dif_i + 1] - a[max_dif_i - 1]));
            }
        }

        cout << diff << endl;
    }

    return 0;
}