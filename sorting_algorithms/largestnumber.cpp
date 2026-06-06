#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>>
#define pb push_back

using namespace std;

 bool cmp(int a, int b){
    string one = to_string(a);
    string two = to_string(b);

    return one + two > two + one;
}

string largestNumber(vector<int>& nums) {
    int sum = 0;

    for(int i: nums){
        sum += i;
    }

    if(sum == 0) return "0";

    sort(nums.begin(), nums.end(), cmp);
    string pal = "";
    for(int i : nums){
        pal += to_string(i);
    }
        
    return pal;
}

int main(){
    vi a = {3,30,34,5,9};
    string res = largestNumber(a);
}