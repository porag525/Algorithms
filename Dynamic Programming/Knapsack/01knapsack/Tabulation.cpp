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

int main()
{
    int n, w;
    cin >> n >> w;

    for (int i = 1; i <= n; i++)
    {
        cin >> wt[i] >> val[i];
    }

    // handle base case

    for (int i = 0; i <= w; i++)
    {
        dp[0][i] = 0;
    }

    // loop over the states

    for (int i = 1; i <= n; i++)
    {
        for (int cap = 0; cap <= w; cap++)
        {

            // calculate the result from smaller sub-problem
            if (cap < wt[i])
            {
                dp[i][cap] = dp[i - 1][cap]; // handle corner case.
            }
            else
            {
                long long ans1 = val[i] + dp[i - 1][cap - wt[i]];
                long long ans2 = dp[i - 1][cap];

                dp[i][cap] = max(ans1, ans2);
            }
        }
    }

    cout << dp[n][w] << endl;
}