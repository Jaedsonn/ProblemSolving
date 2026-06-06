#include <bits/stdc++.h>

using namespace std;


int main()
{
    int l; cin >> l;
    
    for(int k = 0; k < l; k++){
        int n; cin >> n;
        vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];

        int total_sum = 0;
        bool best = true;

        for(int x: a) {
            total_sum += x;
        }
        
        int track = 0;
        int track_size = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > track+a[i]){
                track = a[i];
                track_size = 1;
            } else {
                track += a[i];
                track_size += 1;
            }

            if(track >= total_sum && track_size < n){
                best = false;
                break;
            }
        }

        if(best){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}