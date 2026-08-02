#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vl>
#define qi queue<int>
#define ql queue<ll>
#define pll pair<ll, ll>
#define pb push_back

using namespace std;

class Segtree{
    private:
        vector<pll> st;
        int MAXN = 1;
        pll neutral = {1e9 + 5, 0};
        pll conquer(pll a, pll b){
            if(a.first < b.first) return a;
            if(b.first < a.first) return b;

            return {a.first, a.second + b.second};
        }

    public:
        Segtree(){};
        Segtree(vl &a){
            int N = a.size();

            while(MAXN<N) MAXN*=2;
            st.assign(2*MAXN, neutral);

            for(int i = MAXN;i < MAXN+N;i++){
                st[i] = {a[i - MAXN], 1};
            }

            for(int i = MAXN-1; i > 0; i--){
                st[i] = conquer(st[i<<1], st[(i<<1)+1]);
            }
        }

        void update(int idx, ll value){
            idx  += MAXN;
            st[idx] = {value, 1};
            for(int i = idx>>1; i>0; i >>= 1) st[i] = conquer(st[i<<1], st[(i<<1)+1]);
        }

        pll query(int left, int right){
            left += MAXN;
            right += MAXN;
            pll leftans = neutral;
            pll rightans = neutral;

            while(left <= right){
                if(left&1) leftans = conquer(leftans, st[left++]);
                if(!(right&1)) rightans = conquer(st[right--], rightans);
                left >>= 1;
                right >>= 1;
            }

            return conquer(leftans, rightans);
        }
};

int main(){
    int n, q; cin >> n >> q;
    vl rates(n);
    for(int i = 0; i < n; i++) cin >> rates[i];
    Segtree st(rates);

    for(int i = 0; i < q; i++){
        ll op, a, b; cin >> op >> a >> b;

        if(op == 1){
            st.update(a, b);
        } else {
            pll lrate = st.query(a, b-1);
            
            cout << lrate.first << " " << lrate.second << endl;
        }
    }

    return 0;
}
