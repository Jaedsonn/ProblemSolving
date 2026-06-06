//https://codeforces.com/problemset/problem/58/A
// Greedy

#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    vector<char> pal = {'h', 'e', 'l', 'l', 'o'};
    int k = 0;

    for(int i = 0; i < s.size(); i++){

        if(k >= pal.size()){
            break;
        }

        if(k == 0 && s[i] != pal[k]){
            continue;
        }

        if(k == 0 && s[i] == pal[k]){
            k += 1;
        } else{

            if(s[i] != pal[k] && s[i] != s[i - 1]){
                break;
            }

            if(s[i] == pal[k]){
                k+=1;
                continue;
            }
            if(s[i] == s[i - 1]){
                continue;
            }
        }
    }

    if(k >= pal.size()){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
}