#include <bits/stdc++.h>
using namespace std;
int Matrix_chain_Multiplication(int arr[], int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    int minimum = INT_MAX;
    int count = 0;

    for (int k = i; k < j; k++)
    {
        count = Matrix_chain_Multiplication(arr, i, k) +
                Matrix_chain_Multiplication(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        minimum = min(count, minimum);
    }
    return minimum;
}
int main()
{
    int n;
    cout << "Enter the number of Matrix : ";
    cin >> n;
    int arr[n + 1];
    cout << "Enter the value of matrixs : " << endl;
    for (int i = 0; i < n + 1; i++)
    {
        cin >> arr[i];
    }
    int N = sizeof(arr) / sizeof(arr[0]);
    int ans = Matrix_chain_Multiplication(arr, 1, N - 1);
    cout << "Minimum Cost of the chain matrix multiplication : " << ans << endl;
    return 0;
}
