#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define pb push_back
#define f(l) for(int i = 0; i < l; i++)

using namespace std;

int solve(vi a, int n){
    vi tops;
    tops.pb(a[0]);

    for(int i = 1; i < n; i++){
        auto it = upper_bound(tops.begin(), tops.end(), a[i], std::greater<int>());

        if(it != tops.end()){
            *it = a[i];
        } else {
            tops.pb(a[i]);
        }
    }

    return tops.size();
}

int main(){
    int n; cin >> n;
    vi a(n); f(n) cin >> a[i];

    int res = solve(a, n);
    cout << res << endl;
    return 0;
}