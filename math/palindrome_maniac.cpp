#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b){
	if(b == 0) return a;

	return mdc(b, a % b);
}

int main(){
	int n; cin >> n;

	vector<int> nums(n); for(int i = 0; i < n; i++) cin >> nums[i];

	if(n == 1){
		cout << 0 << endl;
	} else {
		vector<int> ds(n/2);

		for(int i = 0; i < n/2; i++){
			int d = abs(nums[i] - nums[n - i - 1]);
			ds[i] = d;
		}

		int result = ds[0];
		
		for(int i = 1; i < n/2; i++){
			result = mdc(result, ds[i]), result;
		}

		cout << result << endl;

	}

	return 0;
}
