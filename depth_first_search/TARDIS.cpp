#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector < vector < int >>>
#define pb push_back

using namespace std;

bool flag = false;
void percorrer(int l, int c, vector<vector<char>>& m, int search, string pal, string total){
    if(flag) return;
    int linhas = m.size();
    int colunas = m[0].size();

    if (l < 0 || l >= linhas || c < 0 || c >= colunas || m[l][c] != pal[search]) {
        return;
    }

    char temp = m[l][c];
    m[l][c] = ' ';

    total += pal[search];
    search += 1;

    if(total == pal){
        flag = true;
        return;
    }

     percorrer(l, c + 1, m, search, pal, total);
     percorrer(l, c - 1, m, search, pal, total);
     percorrer(l + 1, c, m, search, pal, total);
     percorrer(l - 1, c, m, search, pal, total);

    m[l][c] = temp;
    return;
}

int main()
{
    ll n, m;
    
    cin >> n >> m;
    string pal; cin >> pal;

    vector<vector<char>> adj;

    for (ll i = 0; i < n; i++)
    {
        vector<char> a;

        for(int j = 0; j < m; j++){
            char ch; cin >> ch;
            a.pb(ch);
        }

        adj.pb(a);
    }

    for (ll i = 0; i < n && !flag; i++)
    {
        for(int j = 0; j < m && !flag; j++){
            percorrer(i, j, adj, 0, pal, "");
        }

    }



    if(flag){
        cout << "SIM" << endl;
    } else{
        cout << "NAO" << endl;
    }
    return 0;
}