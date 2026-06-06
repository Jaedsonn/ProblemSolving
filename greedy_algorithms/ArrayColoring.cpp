#include <bits/stdc++.h>
#define ll long long
#define vi vector<ll>
#define vl vector<ll>
#define vii vector < vector < ll >>
#define pb push_back

using namespace std;

int main(){
    int t; cin >> t;

    for(int i = 0; i < t; i++){
        int n; cin >> n;
        vi a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        bool flag = true;
        for(int j = 0; j < n - 2; j+=2){
            if(a[j]%2 == 0 && a[j + 2]%2 == 0) {
                continue;
            } else if(a[j]%2 != 0 && a[j + 2]%2 != 0){
                continue;
            }
            flag = false; 
        }

        if(n == 2){
            cout << "YES" << endl;
        } else if(flag) {
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
}