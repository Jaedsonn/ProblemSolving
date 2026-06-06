#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define pb push_back

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string a;
        cin >> a;

        if (n <= 2)
        {
            cout << 1 << endl;
        }
        else
        {
           

            int count = 0;
            int window = 0;

            for(int i = 0; i < n; i++){
                if(window == 3){
                    count++;
                    continue;
                }

                if(a[i] == '0'){
                    window++;
                } else{
                    int jump = 3 - window;
                    i+= jump - 1;
                }
            }

            cout << count << endl;
        }
    }
    return 0;
}