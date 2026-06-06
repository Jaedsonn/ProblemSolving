#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool ok(ll k, ll c, ll m, ll x) {
    ll remaining_people = (c - k) + (m - k) + x;
    return remaining_people >= k;
}

void solve() {
    ll c, m, x;
    cin >> c >> m >> x;

    ll low = 0;
    ll high = min(c, m);
    ll ans = 0;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (ok(mid, c, m, 
        
        
        
        
        
        )) {
            ans = mid;       
            low = mid + 1;   
        } else {
            high = mid - 1;  
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}