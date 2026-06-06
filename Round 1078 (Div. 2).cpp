#include <bits/stdc++.h>
#define ll long long
#define vi vector<ll>
#define vl vector<ll>
#define vii vector < vector < ll >>
#define pb push_back
#define FOR(n) for(int i = 0; i < n; i++)

using namespace std;

void solveA(){
    ll n, w; cin >> n >> w;

    ll count = 0;
    ll cnt1 = 0;

    for(ll i = 0; i < n; i++){
        if(count < w - 1){
            count ++;
            cnt1++;
        } else{
            count = 0;
        }
    }


    cout << cnt1 << endl;
}

int solveB(){
    
}

int main(){
    int t; cin >> t;

    FOR(t){
    }
    
    return 0;
}