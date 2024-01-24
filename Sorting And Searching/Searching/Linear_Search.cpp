/*

Author : Moniruzzaman Porag
Date of Creation: 20 January 2024
     
           #################
           # Linear Search #
           #################
-----------------
Time Complexity:
-----------------
Best Case :  Ω(1)
Average Case :  θ(n)
Worst Case: O(n)

------------------
Space Complexity:
------------------
Worst Case : O(1)

*/

#include <bits/stdc++.h>
using namespace std;
void Linear_Search(int arr[], int n,int target)
{
   for(int i=0;i<n;i++)
   {
      if(arr[i]==target)
      {
         cout<<target <<" is found at index "<<i<<endl;
         return;
      }
   }
   cout<<target<<" is not found in the array"<<endl;
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
    cout<<"Enter the element which you want to search : ";
    cin>>target;
    Linear_Search(arr,n,target);
}