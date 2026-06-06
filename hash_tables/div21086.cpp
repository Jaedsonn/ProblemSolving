#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	
	for(int k = 0; k < t; k++){
		int n; cin >> n;

		map<int, int> record;

		vector<vector<int>> m;

		for(int j = 0; j < n; j++){
			vector<int> r(n);
			for(int i = 0; i < n; i++){
				int val; cin >> val;
				r[i] = val;

				if(record[val]){
					record[val] += 1;
				} else {
					record[val] = 1;
				}
			}
		}

			int flag = true;

			
			if(n == 1){
				flag = false;
			}  else {
				for(const auto [k, v] : record){
					if(v >= 3*n - 3){
						flag = false;
						break;
					}
				}
			}

			if(flag){
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}


	}

	return 0;
}
