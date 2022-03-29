#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,temp,i,j,count1=0,count2=0;
    cout << "Enter size of array:- ";
    cin >> n;
    int arr[n];
    cout << "Enter data:- ";
    for(i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    for(i=1;i<n;i++)
    {
        temp = arr[i];
        for(j = i-1;j>=0;j--)
        {
            count1++;       //counter for comparision
            if(arr[j] > temp)
            {
                count2++;       // counter for write operations
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
         }
         if(i != j+1)
         {
            count2++;           // counter for write operations
            arr[j+1] = temp;
         }
     }
     cout << "Sorted array is :- ";
     for(i=0;i<n;i++)
    {
        cout <<  arr[i] << " ";
    }
    cout << endl;
    cout << "Comparision:- "<< count1 << endl;
     cout << "write operation:- "<< count2 << endl;
    cout << endl;
    return 0;
}
