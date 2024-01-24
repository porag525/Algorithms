/*

Author : Moniruzzaman Porag
Date of Creation: 20 January 2024

           #################
           # Binary Search #
           #################
-----------------
Time Complexity:
-----------------
Best Case :  Ω(1)
Average Case :  θ(logn)
Worst Case: O(logn)

------------------
Space Complexity:
------------------
Worst Case : O(1)

*/

#include <bits/stdc++.h>
using namespace std;
void Binary_Search(int arr[], int n, int target)
{
    sort(arr, arr + n);
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < target)
        {
            low=mid;
        }
        else if (arr[mid] > target)
        {
            high=mid;
        }
        else
        {
            cout << target << " is found in the array"<< endl;
            return;
        }
    }
     cout << target << " is not found in the array" << endl;
}
int main()
{
    int n;
    cout << "Enter the Size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Enter the element which you want to search : ";
    cin >> target;
    Binary_Search(arr, n, target);
}