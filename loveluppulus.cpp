#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>

using namespace std;

int solve(vl& a, vl& b, ll n){
    vl dp(n+1, 0);
    dp[0] = max(a[0], b[0]);

    bool choose = a[0] > b[0] ? true : false;


    for(int i = 1; i < n; i++){
        if(choose){
            if(dp[i - 1] + b[i] < b[i - 1] + a[i]){
                dp[i - 1] = b[i - 1];
                dp[i] = dp[i - 1] + a[i];
            } else{
                dp[i] = dp[ i - 1] + b[i];
                choose = false;
            }
        } else{
            if(dp[i - 1] + a[i] < a[i - 1] + b[i]){
                dp[i - 1] = a[i - 1];
                dp[i] = dp[i - 1] + b[i];
            } else{
                dp[i] = dp[ i - 1] + a[i];
                choose = true;
            }
        }
    }

    return dp[n - 1];
}

int main(){
    vl a = {1, 2, 3, 4, 5};
    vl b = {1, 2, 3, 4, 5};

    int q = solve(a, b, 5);

    return 0;
}