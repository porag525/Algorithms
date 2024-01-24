/*

Author : Moniruzzaman Porag
Date of Creation: 19 January 2024
     
           #################
           # Bubble  Sort  #
           #################
-----------------
Time Complexity:
-----------------
Best Case :  Ω(n)
Average Case :  θ(n^2)
Worst Case: O(n^2)

------------------
Space Complexity:
------------------
Worst Case : O(1)

*/

#include <bits/stdc++.h>
using namespace std;
void Bubble_Sort(int arr[], int n)
{
    // Bubble Sort:
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
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

    Bubble_Sort(arr, n);
    cout << "The array after Sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}