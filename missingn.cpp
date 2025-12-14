#include <bits/stdc++.h>
#define vi vector<long long>
#define int long long

using namespace std;

signed main(){
    int n; cin >> n;
    vi a(n-1); for(int i = 0; i < n-1; i++) cin >> a[i];

    sort(a.begin(), a.end());

    

    for(int i = 0; i < a.size(); i++){
        if(a[0] != 1){
            cout << "1" << endl; 
            break;
        }

        if(a[a.size() - 1] != n){
            cout << n << endl;
            break;
        }

        if(a[i+1] != a[i] + 1){
            cout << a[i] + 1 << endl;
            break;
        }
    }

    return 0;
}