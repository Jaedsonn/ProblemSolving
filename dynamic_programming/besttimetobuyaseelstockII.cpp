#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>>
#define pb push_back

using namespace std;

int maxProfit(vector<int>& prices){
    int n = prices.size();
    vi dp(n, 0);
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        dp[i] = max(prices[i] - prices[i - 1], 0) + dp[i - 1];
    }

    return dp[n - 1];

}

int main(){
    vi a = {7,1,5,3,6,4};

    int b = maxProfit(a);

    int i = 0;
}