#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define pb push_back
#define f(l) for(int i = 0; i < l; i++)

using namespace std;

int main()
{
    ll t;
    cin >> t;
    
    for (ll k = 0; k < t; k++)
    {
        ll n, q;
        cin >> n >> q;

        vl a(n); f(n) cin >> a[i];
        vl b(n); f(n) cin >> b[i];

        f(n){
            if(a[i] < b[i]){
                a[i] = b[i];
            }
        }

        int l = n;

        while(l--){
            if(a[l] > a[l - 1]) a[l - 1] = a[l];
        }

        vl prefix(n, 0);
        prefix[0] = a[0];

        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + a[i];
        }

        for(int i = 0; i < q; i++){
            int q1, q2; cin >> q1 >> q2;
            q1--;
            q2--;

            int sum = 0;
            if(q1 > 0){
                sum = prefix[q2] - prefix[q1 -  1];
            } else{
                sum = prefix[q2];
            }

            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}