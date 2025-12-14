#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s;
    int max_ocurr = 1;
    int local = 1;

    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i-1]){
            local += 1;
        } else{
            max_ocurr = max(local, max_ocurr);
            local = 1;
        }
    }

    max_ocurr = max(local, max_ocurr);


    cout << max_ocurr << endl;
    return 0;
}