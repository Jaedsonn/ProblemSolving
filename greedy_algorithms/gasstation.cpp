#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>>
#define pb push_back

using namespace std;

int solve2(vi& gas, vi& cost){
    int total_gas = 0;
    int total_cost = 0;
    int n = gas.size();

    if(n == 0) return -1;
    if(n == 1){
        if(gas[0] > cost[0]) return 0;
        else return -1;
    }

    for(int i = 0; i < n; i++){
        total_cost += cost[i];
        total_gas += gas[i];
    }

    if(total_cost > total_gas) return -1;

    int tank = 0;
    int best = -1;
    for(int i = 0; i < n; i++){
        tank += gas[i] - cost[i];
        if(tank < 0){
            best = i + 1;
            tank = 0;
        }
    }

    return best;
}

// TLE
int solve(vi& gas, vi& cost){
    int flag = -1;
    int n = gas.size();

    if(n == 0) return -1;
    if(n == 1) return 0;

    for(int k = 3 ; k < gas.size(); k++){
        int tank = gas[k];

        int i = k == n - 1 ? 0: k + 1;
        int j = k;

        while(i != k){
            if(tank - cost[j] >= 0){
                tank = tank - cost[j] + gas[i];

                i == n - 1 ? i = 0 : i+=1;
                j == n - 1? j = 0 : j+= 1;
            } else{
                break;
            }
        }

        if(tank - cost[j] < 0){
            flag = max(flag, -1);
            continue;
        };
        flag = k;
        break;
    }

    return flag;
}

int main(){
    vi a = {5,1,2,3,4};
    vi b = {4,4,1,5,1};

    int res = solve2(a, b);

    return 0;
}