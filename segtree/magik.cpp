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


class Segtree {
    private:
        vector<ll> st;
        int MAXN = 1;
        ll neutral = 0;

        ll conquer(ll a, ll b) {
            return a + b;
        }

    public:
        Segtree() {};
        Segtree(vl &a) {
            ll N = a.size();

            while (MAXN < N) MAXN *= 2;
            st.assign(2 * MAXN, neutral);

            for (ll i = MAXN; i < MAXN + N; i++) {
                st[i] = a[i - MAXN];
            }

            for (ll i = MAXN - 1; i > 0; i--) {
                st[i] = conquer(st[i << 1], st[(i << 1) + 1]);
            }
        }

        void update(ll idx, int value) {
            idx += MAXN;
            st[idx] = value;
            for (ll i = idx >> 1; i > 0; i >>= 1) {
                st[i] = conquer(st[i << 1], st[(i << 1) + 1]);
            }
        }

        ll query(ll left, ll right) {
            left += MAXN;
            right += MAXN;
            ll leftans = neutral;
            ll rightans = neutral;

            while (left <= right) {
                if (left & 1) leftans = conquer(leftans, st[left++]);
                if (!(right & 1)) rightans = conquer(st[right--], rightans);
                left >>= 1;
                right >>= 1;
            }

            return conquer(leftans, rightans);
        }
};

signed main(){
    ll n, q;
    cin >> n >> q;

    vl querys(q, 0); 
    loop(q) cin >> querys[i];

    vl bits(n + q + 1, 0);
    for (ll i = n + q; i > q; i--){
        bits[i] = 1;
    }
    
    vl deck(n + 1, 0);
    ll helper = q + 1;
    for (int i = 1; i <= n; i++){
        deck[i] = helper;
        helper++;
    }

    ll topo_atual = q;
    Segtree seg = Segtree(bits);

    for(auto query : querys){
        ll pos = deck[query];

        ll above = seg.query(0, pos - 1);
        cout << above << " ";

        seg.update(pos, 0);
        seg.update(topo_atual, 1);
        deck[query] = topo_atual;
        topo_atual--;
    }

    cout << endl;

    return 0;
}
