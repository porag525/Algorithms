/*

Author : Moniruzzaman Porag
Date of Creation: 19 January 2024
     
           ###############
           # Quick  Sort #
           ###############
-----------------
Time Complexity:
-----------------
Best Case : Ω(n log(n))
Average Case :  θ(n log(n))
Worst Case: O(n^2)

------------------
Space Complexity:
------------------
Worst Case : O(n)

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> Quick_sort(vector<int> a)
{
    // Base Case
    if (a.size() <= 1)
    {
        return a;
    }

    int pivot = a.size() - 1; // Select Last element as Pivot;
    vector<int> left;
    vector<int> right;

    // Divide the array into two part.
    for (int i = 0; i < a.size(); i++)
    {
        if (i == pivot)
            continue;
        else if (a[i] <= a[pivot])
        {
            left.push_back(a[i]);
        }
        else
        {
            right.push_back(a[i]);
        }
    }
    // Calling the Quick_sort Function with the divide parts.
    vector<int> sorted_left = Quick_sort(left);
    vector<int> sorted_right = Quick_sort(right);

    // Merge the sorted array.
    vector<int> sorted_a;
    for (int i = 0; i < sorted_left.size(); i++)
    {
        sorted_a.push_back(sorted_left[i]);
    }
    sorted_a.push_back(a[pivot]);
    for (int i = 0; i < sorted_right.size(); i++)
    {
        sorted_a.push_back(sorted_right[i]);
    }

    return sorted_a;
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> ans = Quick_sort(a);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}