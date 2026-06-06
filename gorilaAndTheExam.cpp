// https://codeforces.com/contest/2057/problem/B

#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>>
#define pb push_back

using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vi a(n); for(int i = 0; i < n; i++) cin >> a[i];
    
    if(k == 0){
        cout << a.size();
    } else{
        map <int, int> dict;

        for(int i = 0; i < n; i++){
            if(dict.count(a[i]) == 0){
                dict[a[i]] = 1;
            } else{
                dict[a[i]] += 1;
            }
        }

        int best = a[0];

        for(int i = 0; i < n; i++){
            
        }
    }
}