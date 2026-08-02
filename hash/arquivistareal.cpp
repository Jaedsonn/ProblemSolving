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

signed main(){
    int n; cin >> n;
    set<string> words;

    loop(n) {
        string pal;
        cin >> pal;

        words.insert(pal);
    };

    cout << words.size() << endl;

    return 0;
}