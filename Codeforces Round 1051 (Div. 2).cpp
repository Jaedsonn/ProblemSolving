#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    
    
    for(int i = 0; i < t; i++){
        int n; cin >> n;
        
        vector<int> a(n);
        for(int j = 0; j < n; j++ ) {
            cin >> a[j];
        }
        
        int window = 1;
        for(int j = n ; j >= 0; j--){
            
            int ind1 = -1;
            int ind2 = -1;
            for(int k = 0; k < n; k++){
                if(a[k] == j){
                    ind1 = k;
                    break;
                }
            };

            for(int k = 0; k < n; k++){
                if(a[k] == j - 1){
                    ind2 = k;
                    break;
                }
            };

            if(abs(ind1 - ind2) > window){
                cout << "NO" << endl;
                break;
            } else{
                window++;
            }
        }

        if(window >= n) cout << "YES" << endl;
        
    }
    
    return 0;
}