/*


Author : Moniruzzaman Porag
Date of Creation: 19 January 2024
     
           ##################
           # Insertion Sort #
           ##################
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
void Insertion_Sort(int arr[], int n)
{
    // Insertion Sort:
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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