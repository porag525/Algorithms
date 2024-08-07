#include <bits/stdc++.h>
using namespace std;

/*
   1. state: knapsack(n,cap) -> maximum profit considering objects 1 to n and capacity cap
   2. reocurrance:
       knapsack(n,cap) -> max{
                               val[n]+knapsack(n-1,cap-wt[n]),
                               0+knapsack(n-1,cap)

                            }
   3.base_case: knapsack(0,x) = 0;

*/
const int N = 105;
const int M = 1e5 + 5;
long long dp[N][M];
int wt[N];
int val[N];

long long knapsack(int n, int cap)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    // if result is already calculated return it;
    if (dp[n][cap] != -1)
    {
        return dp[n][cap];
    }

    // calculate answer from smaller sub-problems

    if (cap < wt[n]) // handle a corner case
    {
        long long ans = knapsack(n - 1, cap);
        dp[n][cap] = ans;
        return ans;
    }

    long long ans1 = val[n] + knapsack(n - 1, cap - wt[n]);
    long long ans2 = 0 + knapsack(n - 1, cap);

    long long ans = max(ans1, ans2);
    dp[n][cap] = ans;
    return ans;
}

int main()
{
    int n, cap;
    cin >> n >> cap;

    for (int i = 1; i <= n; i++)
    {
        cin >> wt[i] >> val[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= cap; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n, cap) << endl;
    return 0;
}