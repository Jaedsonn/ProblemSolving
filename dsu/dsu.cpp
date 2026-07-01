#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vl>
#define pb push_back

using namespace std;

vi parent(1e5);
vi tsize(1e5, 0);

void make_set(int v){
    parent[v] = v;
    tsize[v] = 1;
}

int find_set(int v){
    if(v == parent[v]){
        return v;
    }

    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if(a != b){
        if(tsize[a] < tsize[b]){
            swap(a, b);
        }

        parent[b] = a;
        tsize[a] += tsize[b];
    }
}
