#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    
    for(int k = 0; k < t; k++){
        int n; cin >> n;
        
        vector<long long> a(n); for(int i = 0; i < n; i++) cin >> a[i];
        
        set<int>  dist;
        
        for(int i = 0; i < n; i++){
            dist.insert(a[i]);
        }
        
        int distincts = dist.size();
        
        int repeat = 0;
        
        while(true){
            a.push_back(distincts);
            dist.insert(distincts);
            
            if(distincts == dist.size()) break;
            distincts = dist.size();
        }
        
        cout << distincts << endl;
    }
    
    return 0;
}