#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][i] = 1;
        dp[i][0] = 1;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= min(i - 1, k); j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}