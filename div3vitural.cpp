    #include<bits/stdc++.h>
     
    using namespace std;

    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = 1;

        for(int i = 1; i < nums.size(); i++){
            int best = 1;
            for(int j = i-1; j >= 0; j--){
                if(nums[i] > nums[j]){
                    best = max(dp[i-1]+1, best);
                }
            }

            dp[i] = best;
        }

        return dp[nums.size() - 1];
    }
     
    int main(){
        int t; cin >> t;
        
        for(int h = 0; h < t; h++){
            int n; cin >> n;
            vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];
            vector<int> sorted_a = a;
            
            sort(sorted_a.begin(), sorted_a.end());

            if(sorted_a == a){
                cout << n << endl;
            } else{
                int lis = lengthOfLIS(a);

                cout << n - lis << endl;
            }
        }
        
        return 0;
    }