#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vi apples(n); for (int i = 0; i < n; ++i) cin >> apples[i];

    ll ans = 1e18;
    for (int mask=0;mask<(1<<n);mask++) {
        ll group1=0, group2=0;
        for (int j=0;j<n;j++) {
            if (mask & (1<<j)) group1 += apples[j];
            else group2 += apples[j];
        }
        ans = min(ans, abs(group1-group2));
    }

    cout << ans;
}