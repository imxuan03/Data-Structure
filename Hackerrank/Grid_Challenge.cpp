#include <bits/stdc++.h>

using namespace std;

int check()
{
    int n;
    cin >> n;
    string grids[n];
    for (int i = 0; i < n; i++)
    {
        cin >> grids[i];
    }

    for (int i = 0; i < n; i++)
        sort(grids[i].begin(), grids[i].begin() + n);
    
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (grids[i][j] > grids[i + 1][j])
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        if (check())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}