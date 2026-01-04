// https://codeforces.com/contest/158/problem/B

#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>>
#define pb push_back

using namespace std;

int main(){
    int n; cin >> n;
    vi groups(n);

    for(int i = 0; i < n; i++) cin >> groups[i];

    
    sort(groups.begin(), groups.end());
    
    int i = 0;
    int j = n - 1;
    int taxis = 0;
    int sum = groups[i] + groups[j];

    if(n == 1){
        i = j + 1;
        taxis = 1;
    }

    while(i <= j){
        if(i == j){
            taxis += 1;
            break;
        }

        if(i + 1 == j){
            if(sum <= 4){
                taxis += 1;
                break;
            } else{
                taxis += 2;
                break;
            }
        }

        if(groups[j] == 4 || sum > 4){
            taxis += 1;
            j -= 1;
            sum = groups[i] + groups[j];
        } else if(sum == 4){
            taxis += 1;
            j -= 1;
            i += 1;
            sum = groups[i] + groups[j];
        } else{
            i+= 1;
            sum += groups[i];
        }
    }

    cout << taxis << endl;

    return 0;
}