#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        dp[i][i] = 0;
    for (int i = N - 2; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int ans = arr[i - 1] * arr[j] * arr[k] + dp[i][k] + dp[k + 1][j];
                mini = min(mini, ans);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dim(n);
    for (auto &it : dim)
    {
        cin >> it;
    }
    cout << matrixMultiplication(dim, n) << endl;
    return 0;
}