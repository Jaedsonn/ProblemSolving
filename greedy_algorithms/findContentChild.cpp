#include <bits/stdc++.h>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0;
        int j = 0;

        while(j < s.size() && i < g.size()){
            if(s[j] >= g[i]){
                j+= 1;
                i+= 1;
            } else{
                j+= 1;
            }
        }

        return i;
    }