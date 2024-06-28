/*


Author : Moniruzzaman Porag
Date of Creation: 20 January 2024
     
           ##############
           #  Heap Sort #
           ##############
-----------------
Time Complexity:0
-----------------
Best Case :  Ω(nlogn)
Average Case :  θ(nlogn)
Worst Case: O(nlogn)

------------------
Space Complexity:
------------------
Worst Case : O(1)

*/

#include <bits/stdc++.h>
using namespace std;
void Max_Heapify(int arr[],int n,int i)
{
     // Initialize largest as root
    int largest=i;
     // left child = 2*i + 1
    int left=2*i+1;
     // right child = 2*i + 2
    int right=2*i+2;

     // If left child is larger than root
    while (left<n && arr[left]>arr[largest])
    {
        largest=left;
    }

     // If right child is larger than largest
    while (right<n && arr[right]>arr[largest])
    {
        largest=right;
    }

     // If largest is not root
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);

        // Recursively heapify the affected sub-tree
        Max_Heapify(arr,n,largest);
    }
    


}
void Heap_Sort(int arr[], int n)
{
   // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)//
        Max_Heapify(arr, n, i);

    // One by one extract an element
    // from heap
    for (int i = n - 1; i > 0; i--) {
 
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        Max_Heapify(arr, i, 0);
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
    Heap_Sort(arr,n);

    cout << "The array after Sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}