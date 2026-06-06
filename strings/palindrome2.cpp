#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int skip, int left, int right)
{
    int n = s.size();

    int r = right;
    int l = left;

    bool flag = true;

    while (l < r)
    {
        if (r == skip)
        {
            r--;
        }

        if (l == skip)
        {
            l++;
        }

        if (s[r] != s[l])
        {
            flag = false;
            break;
        }

        r--;
        l++;
    }
    return flag;
}

bool validPalindrome(string s)
{
    int n = s.size();

    int r = n - 1;
    int l = 0;
    bool res = true;

    int retired = 0;

    while (l < r)
    {

        if (s[l] != s[r])
        {
            if (l + 1 == r || r - 1 == l)
            {
                break;
            }

            if (isPalindrome(s, r, l, r))
            {
                break;
            }
            else if (isPalindrome(s, l, l, r))
            {
                break;
            }
            else
            {
                res = false;
                break;
            }
        }

        if (retired == 2)
        {
            res = false;
            break;
        }

        r--;
        l++;
    }

    return res;
}



int main()
{

    validPalindrome("ebcbbececabbacecbbcbe");

    return 0;
}