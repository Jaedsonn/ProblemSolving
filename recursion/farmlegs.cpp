    //https://codeforces.com/contest/2171/problem/A
    #include <bits/stdc++.h>

    using namespace std;
    
    int solve(int n, int current_legs, bool apenasVacas){
     
     
        int confs = 0;
     
    	if(n%2 != 0){
    		return 0;
    	}
     
        if(!apenasVacas && current_legs + 4 <= n){
            confs += solve(n, current_legs + 4, false);
        }
     
        if(current_legs + 2 <= n){
            confs += solve(n, current_legs + 2, true);
        }
     
        if(current_legs + 4 > n && current_legs + 2 > n){
            return 1;
        }
        
        return confs;
    }
     
    int main(){
    	int n; cin >> n;
    	for(int i = 0; i < n; i++){
    	    int k; cin >> k;
    	    int confs = solve(k, 0, 0);
    	    cout << confs << endl;
    	}
    	
    	return 0;
    }