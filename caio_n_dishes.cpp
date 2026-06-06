#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define pb push_back
#define f(l) for(int i = 0; i < l; i++)

using namespace std;

ll solve(int n, int m, int k, vl dishes, vector<vl> rules){
    vl place(n, 0);
    vector<vl> dp( 1 << n, place);

    for(int i = 0; i < n; i++){
        int mask = 1 << i;
        dp[mask][i] = dishes[i];
    }

    for(int i = 0; i < ( 1 << n); i++){
        for(int j = 0; j < n; j++){

            if((i & (1 << j)) == 0) continue;

            for(int k = 0; k < n; k++){
                if ((i & (1 << k)) != 0) continue;

                ll raise = rules[j][k];

                int mask = i | (1 << k);
                dp[mask][k] = max(dp[mask][k], dp[i][j] + dishes[k] + raise);
            }

        }
    }

    ll best = 0;

    for (int i = 0; i < (1 << n); i++) {
        if (__builtin_popcount(i) == m) {
            
            for (int last = 0; last < n; last++) {
                best = max(best, dp[i][last]);
            }
        }
    }

    return best;

}

int main(){
    int n, m, k; cin >> n >> m >> k;
    vl dishes(n); f(n) cin >> dishes[i];
    
    vl place(n, 0);
    vector<vl> rules(n, place);

    for(int i = 0; i < k; i++){
        int x, y, c; cin >> x >> y >> c;

        rules[--x][--y] = c;
    }

    ll res = solve(n, m, k, dishes, rules);

    cout << res << endl;

    return 0;
}