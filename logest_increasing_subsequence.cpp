#include <bits/stdc++.h>
#define vi vector<int>
#define vl vector<long long>

using namespace std;

int ans = 0;
int last = -1;

int solve(vi& a, int x){
    if(x == 0){
        last = 0;
        return 1;
    }

    
    ans += solve(a, x-1);

    for(int i = x; i > last; i-=1){
        if(a[i] > a[last]){
            ans += 1;
            break;
        }
    }

}

int main(){
    vector<int> a = {
        0,1,0,3,2,3
    };

    solve(a, a.size() - 1);

    return 0;
}