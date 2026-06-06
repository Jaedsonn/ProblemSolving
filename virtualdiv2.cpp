#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define pb push_back
#define FOR(n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
    int t; cin >> t;

    FOR(t){
        int n; cin >> n;
        vl a(n); FOR(n) cin >> a[i];

        

        int count = 0;
        
        for(int l = 0; l < n; l++){
            for(int r = l+1; r < n; r++){
                if(a[l] == -1){
                    break;
                }

                if(a[r] == -1){
                    continue;
                }

                if(a[l] > a[r]){
                    count ++;
                    a[r] = 1;
                } else{
                    break;
                }
            }
                
        }

        cout << count << endl;
    }
}