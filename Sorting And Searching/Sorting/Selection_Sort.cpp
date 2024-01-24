/*


Author : Moniruzzaman Porag
Date of Creation: 19 January 2024
     
           ##################
           # Selection Sort #
           ##################
-----------------
Time Complexity:
-----------------
Best Case :  Ω(n^2)
Average Case :  θ(n^2)
Worst Case: O(n^2)

------------------
Space Complexity:
------------------
Worst Case : O(1)

*/

#include <bits/stdc++.h>
using namespace std;
void Selection_Sort(int arr[], int n)
{
    // Selection Sort:
    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[index]) // selecting the minimum value of the array to swap.
            {
                index = j;
            }
        }
        if (index != i)
        {
            swap(arr[i], arr[index]);
        }
    }
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

    cout << "The array after Sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}