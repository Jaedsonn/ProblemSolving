#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>

using namespace std;

int solve(vl &pales, vl &large, ll n)
{
    vl dpp(n + 1, 0);
    vl dpl(n + 1, 0);
    
    ll maxp = pales[0];
    ll maxl = large[0];

    dpp[0] = maxp;
    dpl[0] = maxl;

    for(int i = 1; i < n; i+=1){
        dpp[i] = max(dpp[i - 1], dpl[i - 1] + pales[i]);

        dpl[i] = max(dpl[i - 1], dpp[i - 1] + large[i]);
    }

    return max(dpp[n - 1], dpl[n - 1]);
}

int main()
{
    int n;
    cin >> n;
    vl a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vl b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    int q = solve(a, b, n);
    cout << q << endl;

    return 0;
}