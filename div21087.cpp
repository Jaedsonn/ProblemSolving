#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int t;
    cin >> t;

    for (int k = 0; k < t; k++)
    {
        int n, c, f;
        cin >> n >> c >> f;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++)
        {
            if (a[i] <= c)
            {

                if (a[i] == c)
                {
                    c += a[i];
                    a[i] = -1;
                } else {
                    int aux = c - a[i];

                    if(aux > f){
                        a[i] += f;
                        f = 0;
                        c += a[i];
                    } else {
                        a[i] += aux;
                        f -= aux;
                        c+= a[i];

                        f = f < 0 ? 0: f;
                    }
                }
            }
        }

        cout << c << endl;
    }

    return 0;
}