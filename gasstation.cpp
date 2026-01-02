#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>>
#define pb push_back

using namespace std;

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
    vi a = {5,8,2,8};
    vi b = {6,5,6,6};

    int res = canCompleteCircuit(a, b);

    return 0;
}