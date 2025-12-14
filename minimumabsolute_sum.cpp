// https://codeforces.com/contest/2171/my
#include <bits/stdc++.h>
#define long long int

using namespace std;

signed main()
{
    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; j++)
            cin >> a[j];

        if (a[a.size() - 1] == -1)
            a[a.size() - 1] = a[0];
        if (a[0] == -1)
            a[0] = a[a.size() - 1];

        int diff = abs(abs(a[a.size() - 1]) - abs(a[0]));

        for (int y = 0; y < n; y++)
        {
            if (a[y] == -1)
            {
                a[y] = 0;
            }
        }

        cout << diff << endl;
        for (int l = 0; l < a.size(); l++)
        {
            cout << a[l] << " ";
        }

        cout << endl;
    }
}