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

class SparseTable {
    using T = int;
    vector<vector<T>> spt;
    int floorLog2N;
    T conquer(T a, T b);
    public:
    SparseTable(vector<T>& values);
    T query(int left, int right);
};
SparseTable::T SparseTable::conquer(T a, T b) {
    return __gcd(a, b);
}
SparseTable::SparseTable(vector<T>& values) {
    int N = values.size();
    floorLog2N = __lg(N);
    spt.resize(floorLog2N + 1);
    for (int i = 0; i <= floorLog2N; i++)
    spt[i].assign(N - (1 << i) + 1, -1);
    
    for (int i = 0; i < N; i++)
    spt[0][i] = values[i];
    
    for (int i = 1; i <= floorLog2N; i++)
    for (int j = 0; j <= N - (1 << i); j++)
    spt[i][j] = conquer(spt[i - 1][j],
    spt[i - 1][j + (1 << (i - 1))]);
}
SparseTable::T SparseTable::query(int left, int right) {
    int lg = __lg(right - left + 1);
    return conquer(spt[lg][left],
    spt[lg][right - (1 << lg) + 1]);
}

signed main(){
    int n; cin >> n;

    vi a(n); loop(n) cin >> a[i];
    SparseTable st(a);
    int querys; cin >> querys;

    loop(querys){
        int l, r;
        cin >> l >> r;

        cout << st.query(l, r) << endl;
    }

    return 0;
}