#include <bits/stdc++.h>

using namespace std;

//solve
int A(){
    int t; cin >> t;

    for(int i = 0; i < t; i++){
        int n; cin >> n;
        string s; cin >> s;

        int count = -1;

        for(int j = 0; j < n; j++){
            string local = "";
            for(int k = j; k <= j+4 && k <= n; k++){

                if(local == "2025"){
                    count = 1;
                    break;
                }else if(local == "2026"){
                    count = 0;
                    break;
                }
                local += s[k];
            }

            if(local == "2026") break;
        }

        if(count > 0){
            cout << 1 << endl;
        } else{
            cout << 0 << endl;
        }
    }
}

// upsolving
int B(long long a, long long b){
    int layer = 1;
    int i = 0;

    while(true){
        if(i%2 == 0){
            if(a - layer >= 0){
                a -= layer;
                layer *= 2;
                i += 1;
            } else{
                break;
            }
        } else{
            if(b - layer >= 0){
                b -= layer;
                layer *= 2;
                i += 1;
            } else{
                break;
            }
        }
    }

    return i;
}