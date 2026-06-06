#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end(), 
        [](const string &a, const string &b){
            return a.size() < b.size();
        });

        string max = "";
        string local = "";
        for(int i = 0; i < strs[0].size(); i++){
            int isCommon = true;
            for(int j = 0; j < strs.size(); j++){
                if(strs[j][i] != strs[0][i]) isCommon = false;             
            }

            if(isCommon){
                local += strs[0][i];
            } else{
                max = local.size() > max.size() ? local : max;
                local = "";
            }
        }

        return local.size() > max.size() ? local : max;
}

int main(){
    vector<string> a = {"cir","car"};

    string max = longestCommonPrefix(a);

    return 0;
}