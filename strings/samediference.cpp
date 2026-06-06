// https://codeforces.com/contest/2166/problem/A

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;

    for(int i = 0; i < t; i++){
        int n; cin >> n;
        string pal; cin >> pal;

        int min_p = 0;
        

        for(int j = 0; j < n - 1; j++){
            if(pal[j] != pal[pal.size() - 1]) min_p +=1;            
        }

        cout << min_p << endl;
    }
}