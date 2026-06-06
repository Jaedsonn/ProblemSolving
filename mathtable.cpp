#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int k = 0; k < t; k++)
    {
        int n, h, w;
        cin >> n >> h >> w;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        sort(p.begin(), p.end());

        int pairs = 0;
        
        
            int i = 0;
            int j = n - 1;

            while (i < j)
            {
                if (p[i] <= w && p[j] <= h)
                {
                    i++;
                    j--;
                    pairs++;
                }
                else if (p[j] <= w && p[i] <= h)
                {
                    i++;
                    j--;
                    pairs++;
                }
                else if (p[i] > w)
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }
        

        cout << pairs << endl;
    }

    return 0;
}