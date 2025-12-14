#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>

using namespace std;

int main(){
    int n; cin >> n;
    vl a(n); for(int i = 0; i < n; i++) cin >> a[i];

    ll moves = 0;
    for(int i = 1; i < n; i++){
        if(a[i] < a[i-1]){
            ll move = abs(a[i] - a[i-1]);
            a[i] = a[i] + move;
            moves += move;
        }
    }

    cout << moves << endl;
    return 0;
}