#include <bits/stdc++.h>
#define ll long long
#define vi vector<ll>
#define vl vector<ll>
#define vii vector < vector < ll >>
#define pb push_back

using namespace std;


    bool lemonadeChange(vector<int> bills) {
        int q5 = 0;
        int q10 = 0;
        int q20 = 0;
        bool flag = true;

        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                q5++;
            } else if(bills[i] == 10){
                if(q5 == 0) {
                    flag = false;
                    break;
                };
                q5--;
                q10++;
            } else {
                if(q5 >= 1 && q10 >= 1){
                    q20++;
                    q5--;
                    q10--;
                } else if(q5 >= 3){
                    q5-=3;
                    q20++;
                } else {
                    flag = false;
                    break;
                }
            }
        }

        return flag;
    }


int main(){
    lemonadeChange({5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5});
    return 0;
}