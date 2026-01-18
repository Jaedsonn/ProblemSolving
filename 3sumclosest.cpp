#include <bits/stdc++.h>
#define ll long long
#define vi vector<ll>
#define vl vector<ll>
#define vii vector < vector < ll >>
#define pb push_back

// https://leetcode.com/problems/3sum-closest/description/?envType=problem-list-v2&envId=array
using namespace std;

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),  nums.end());

        bool flag = true;
        int best = 1e5;
        for(int k = 0; k < nums.size() && flag; k++){
            int i = k + 1;
            int j = nums.size() - 1;
            int best_local = 1e5;

            while(i != j && i <= j){
                int sum = nums[i] + nums[j] + nums[k];
                int diff = sum - target;
                if(abs(diff) < abs(best - target)){
                    best = sum;
                }

                if(sum < target){
                    i+=1;
                } else{
                    j-=1;
                }
            }
        }

        return best;
    }


int main(){
    int target = 1;

    vector<int> a = {10,20,30,40,50,60,70,80,90};
    
    int res = threeSumClosest(a, target);

    return 0;
}