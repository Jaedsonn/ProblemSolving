#include <bits/stdc++.h>
#define ll long long
#define vi vector<ll>
#define vl vector<ll>
#define vii vector<vector<ll>>
#define pb push_back

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        ll min_a = a[0];
        int count_zero = 0;
        int count_one = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
                count_zero++;
            if (a[i] == 1)
                count_one++;
        }

        if (count_zero == 0)
        {
            cout << "NO" << endl;
        }
        else if (count_one == 0 && count_zero > 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}