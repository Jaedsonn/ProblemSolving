//https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(string dig, string pal, unordered_map<char, string> dict, int ind,vector<string> &pals){
        if(pal.size() == dig.size()) {
            pals.push_back(pal);
            return;
        };

        for(int i = 0; i < dict[dig[ind]].size(); i++){
            solve(dig, pal + dict[dig[ind]][i], dict, ind+1, pals);
        }   
    }

vector<string> letterCombinations(string digits) {
    
    vector<string> pals;
    unordered_map<char, string> dict = {
            {'2', "abc" },
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}

    };

    solve(digits, "", dict, 0, pals);
    return pals;
}  
};