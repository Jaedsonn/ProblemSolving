#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    
    for(int i = 0; i < t; i++){
        int n; cin >> n;
        string p; cin >> p; 

        int cnta = 0;
        int cntb = 0;

        for(int j = 0; j < n; j++){
            if(p[j] == 'a') cnta++;
            if(p[j] == 'b') cntb++;
        }

        if(cnta == cntb){
            cout << 0 << endl;
        } else{
            int window = 1;
            char letter = p[0];

            int flag = -1;
            
            for(int j = 1; j <= n; j++){
                if(letter == 'a' && cnta - window == cntb) {
                    flag = window;
                    break;
                };

                if(letter == 'b' && cntb - window == cnta) {
                    flag = window;
                    break;
                };

                if(j == n) break;

                if(p[j] ==  letter){
                    window++;
                } else{
                    window = 1;
                    letter = p[j];
                }
            }

            cout << flag << endl;
        }
        
    }
    return 0;
}