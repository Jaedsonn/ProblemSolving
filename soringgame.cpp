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
        string a; cin >> a;

        int moves = 0;

        for(int j = 0; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(a[j] == 0){
                    if(a[k] == 1){
                        
                    }
                }
            }
        }

        if(moves%2 != 0){
            cout << "Bob" << endl;
        } else{
            cout << "Alice" << endl;
        }
    }
}