#include <bits/stdc++.h>
using namespace std;

int min_goals = 1e5;

void solve(string pal, int g1, int g2, int u, int r1, int r2){

    if(g1 > g2 + r2){
        min_goals = min(min_goals, u);
        return;
    }

    if(g2 > g1 + r1){
        min_goals = min(min_goals, u);
        return;
    }

    if(u >= pal.size()){
        min_goals = min(min_goals, u);
        return;
    }

    if(u%2 == 0){
        if(pal[u] == '1'){
            g1 += 1;
            solve(pal, g1, g2, u+1, r1 - 1, r2);
        } else if(pal[u] == '?'){
            // a gente considera pal[u] como 1
            solve(pal, g1+1, g2, u+1, r1 - 1, r2);

            // a gente considera pal pal[u] como 0
            solve(pal, g1, g2, u+1, r1 - 1, r2);
        } else{
            solve(pal, g1, g2, u+1, r1 - 1, r2);
        }
    } else{
        if(pal[u] == '1'){
            g2 += 1;
            solve(pal, g1, g2, u+1, r1, r2 - 1);
        } else if(pal[u] == '?'){
            // a gente considera pal[u] como 1
            solve(pal, g1, g2+1, u+1, r1, r2 - 1);

            // a gente considera pal pal[u] como 0
            solve(pal, g1, g2, u+1, r1, r2 - 1);
        } else{
            solve(pal, g1, g2, u+1, r1, r2 - 1);
        }
    }
}

int main() {
    string pal; cin >> pal;
    solve(pal, 0, 0, 0, pal.size()/2, pal.size()/2);

    cout << min_goals << endl;


    return 0;
}
