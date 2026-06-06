// https://codeforces.com/contest/2183/problem/B

#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>>
#define pb push_back

using namespace std;

int mex(vi& a, int l, int r){
    vector<int> b(1e5);
    int mex = -1;

    for(int i = l; i <= r; i++){
        b[a[i]] = 1;
    }

    for(int i = 0; i < b.size(); i++){
        if(b[i] == 0){
            mex = i ;
            break;
        }
    }

    return mex;
}

int main(){
    vi a = {0,1,3};
    int res = mex(a, 0, 2);

    return 0;
}