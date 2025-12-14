#include <bits/stdc++.h>

using namespace std;

vector<int> values(1e5, -1);

int coinChange(vector<int> &coins, int amount)
{

    int best = 1e5;
    if (amount < 0)
        return -1;

    if (amount == 0)
        return 0;

    if (values[amount] != -1)
        return values[amount];

    for (auto c : coins)
    {
        int res = coinChange(coins, amount - c);

        if (res != -1)
        {
            best = min(best, res + 1);
        }
    }

    values[amount] = (best == 1e5) ? -1 : best;

    return values[amount];
}

int main()
{
    vector<int> coins = {2};
    int amount = 3;

    sort(coins.begin(), coins.end());

    int best = coinChange(coins, amount);

    cout << best << endl;
    return 0;
}