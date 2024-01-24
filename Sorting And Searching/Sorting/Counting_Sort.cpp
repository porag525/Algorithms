/*
Author : Moniruzzaman Porag
Date of Creation: 19 January 2024
     
           #################
           # Counting Sort #
           #################
           
-----------------
Time Complexity: 
-----------------
Best Case :  Ω(n+k)
Average Case :  θ(n+k)
Worst Case: O(n+k)

------------------
Space Complexity:
------------------
Worst Case : O(k)

*/

#include <bits/stdc++.h>
using namespace std;
int find_max(int arr[],int n)
{
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}

void Counting_Sort(int arr[],int n)
{
    int max=find_max(arr,n);
    int countArray[max+1]={0};

    for(int i=0;i<n;i++)
    {
        countArray[arr[i]]++; //Count the occurnace of every number;
    }

    for(int i=1;i<=max;i++)  // Prefix Sum;
    {
        countArray[i]=countArray[i]+countArray[i-1]; 
    }
    int  tmp[n];
    for(int i=n-1;i>=0;i--) // Place the number to the sorted place;
    {
        tmp[countArray[arr[i]]-1]=arr[i]; 
        countArray[arr[i]]--;

    }
    for(int i=0;i<n;i++)
    {
        arr[i]=tmp[i];
    }
    int i=0,j=0;
    // while(i<=max)
    // {
    //     if(countArray[i]>0)
    //     {
    //         arr[j]=i;
    //         countArray[i]--;
    //         j++;
    //     }
    //     else{
    //         i++;
    //     }
    // }
   


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
    Counting_Sort(arr,n);
    cout << "The array after Sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}