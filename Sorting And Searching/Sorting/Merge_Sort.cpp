/*

Author : Moniruzzaman Porag
Date of Creation: 19 January 2024
     
           ###############
           # Merge  Sort #
           ###############
-----------------
Time Complexity: 
-----------------
Best Case : Ω(n log(n))
Average Case :  θ(n log(n))
Worst Case: O(n log(n))

------------------
Space Complexity:
------------------
Worst Case : O(n)

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> Merge_sort(vector<int> a)
{
    // Base Case
    if (a.size() <= 1)
    {
        return a;
    }

    int mid = a.size() / 2;
    vector<int> b;
    vector<int> c;

    // Divide the array into two part.
    for (int i = 0; i < mid; i++)
    {
        b.push_back(a[i]);
    }
    for (int j = mid; j < a.size(); j++)
    {
        c.push_back(a[j]);
    }

    // Calling the Merge_sort Function with the divide parts.
    vector<int> sorted_b = Merge_sort(b);
    vector<int> sorted_c = Merge_sort(c);

    vector<int> sorted_a;
    int idx_1 = 0;
    int idx_2 = 0;
    int size = a.size();

    //Merge the array.
    for (int i = 0; i < size; i++)
    {
        if (idx_1 == sorted_b.size())
        {
            sorted_a.push_back(sorted_c[idx_2]);
            idx_2++;
        }
        else if (idx_2 == sorted_c.size())
        {
            sorted_a.push_back(sorted_b[idx_1]);
            idx_1++;
        }
        if (sorted_b[idx_1] < sorted_c[idx_2])
        {
            sorted_a.push_back(sorted_b[idx_1]);
            idx_1++;
        }
        else
        {
            sorted_a.push_back(sorted_c[idx_2]);
            idx_2++;
        }
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
        cin>>a[i];
    }
    vector<int>ans=Merge_sort(a);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}