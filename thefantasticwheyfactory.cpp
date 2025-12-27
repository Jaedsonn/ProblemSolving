#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>
#define pb push_back

using namespace std;

int main() {
    ll n, m, c0, d0; cin >> n >> m >> c0 >> d0;

    vl dp(n + 1, 0);

    for (ll i = 0; i < m; ++i) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        ll max_itens = a / b; 
        
        for (ll k = 0; k < max_itens; ++k) {
            for (ll j = n; j >= c; j--) {
                dp[j] = max(dp[j], dp[j - c] + d);
            }
        }
    }

    for (ll j = c0; j <= n; ++j) {
        dp[j] = max(dp[j], dp[j - c0] + d0);
    }

    cout << dp[n] << endl;

    return 0;
}