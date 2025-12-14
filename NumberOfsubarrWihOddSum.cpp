
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> a, vector<int> b, int n){
    
    int sum = 0;
    int best = 0;
    bool ch = true;
    for(int i = 0; i < n; i++){
        if(ch){
            if(a[i] - b[i] > 0){
                sum += a[i];
                ch = false;
            } else{
                int k = i;
                while(a[k] - b[k] <= 0 && k < n){
                    k++;
                }
                if(k < n){
                    sum += a[k];
                    ch = false;
                } else{
                    sum += b[k - (k - 1)];
                }
            }
        } else{
            int k = i;
            if(b[i] - a[i] > 0){
                sum += b[i];
            } else{
                while(b[k] - a[k] <= 0 && k < n){
                    k++;
                }
                if(k < n) sum += b[k];
                else sum += a[k - (k - 1)];
                ch = true;
            }
        }
    }

    sum += best;

    return sum;

}

int main() {
    vector<int> a = {10, 1, 1};
    vector<int> b = {1,2,9};
    int res = solve(a, b, a.size() - 1);
    cout << res << endl;
    return 0;
}
