#include <bits/stdc++.h>

#define int long long
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vl>
#define qi queue<int>
#define ql queue<ll>
#define pll pair<ll, ll>
#define pb push_back
#define loop(b) for(int i = 0; i < b; i++)

using namespace std;

int prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }

    return *max_element(pi.begin(), pi.end());
}

signed main(){
    int n;
    cin >> n;
    string a; cin >> a;
    string b; cin >> b;

    int res = prefix_function(a + "#" + b + b);

    cout << res-n << endl;

    return 0;
}