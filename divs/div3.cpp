#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vl>
#define pb push_back

using namespace std;

void solveA(int x, int y){
    if (x%y == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

void solveB(int x, int y){
    if(x < 10){
        cout << 2 << endl;
    } else if(x % 10 == 0) {
        cout << 10 << endl;
    } else {
        
    }
    
}

int main(){
    int t; cin >> t;

    while(t--){
        int x, y; cin >> x >> y;
        solveA(x, y);
    }
    return 0;
}