#include <bits/stdc++.h>;

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool flag = false;
        if(n == 1 && flowerbed.size() == 1 && flowerbed[0] == 0) return true;

        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 1) continue;
            if(i == flowerbed.size() - 1){
                if(flowerbed[i - 1] == 0){
                    n-=1;
                    flowerbed[i] = 1;
                }
            }
            else if(i == 0){
                if(flowerbed[i + 1] == 0){
                    n-=1;
                    flowerbed[i] = 1;
                }
            }
            else if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                n-= 1;
                flowerbed[i] = 1;
            };
        }

        return n <= 0;
    }

int main(){
    vector<int> a = {0, 1, 0};
    bool b = canPlaceFlowers(a, 1);
    return 0;
}