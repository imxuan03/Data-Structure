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
    // // sort theo hang
    // for (int i = 0; i < n; i++)
    // {
    //     // so hang
    //     for (int j = 0; j < n - 1; j++)
    //     {
    //         // sort trong 1 hang
    //         for (int k = j + 1; k < n; k++)
    //         {
    //             if (j < n && A[i][j] > A[i][k])
    //                 swap(A[i][j], A[i][k]);
    //         }
    //     }
    // }
    //kiem tra hang doc
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