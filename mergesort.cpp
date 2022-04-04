// MERGE  SORT WITH NO. OF COMPARISION

#include <iostream>
using namespace std;
int* merge(int *arr,int l,int mid,int h,int *comp)
{
    int i=l,j=mid+1,k=l;
    int brr[h+1];
    while(i <= mid && j <= h)
    {
        *comp = *comp + 1;
        if(arr[i] < arr[j])
        {
            brr[k++] = arr[i++];
        }
        else{
            brr[k++] = arr[j++];
        }
    }
    while(i <= mid)
    {
        brr[k++] = arr[i++];
    }
    while(j <= h)
    {
        brr[k++] = arr[j++];
    }
    for(int p=l;p<=h;p++)
    {
        arr[p] = brr[p];
    }
    return comp;
}
int merge_sort(int *arr,int l,int h)
{
    static int comp = 0;
    int mid;
    if(l < h)
    {
        mid = (l+h)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,h);
        merge(arr,l,mid,h,&comp);
    }
    return comp;
}
int main()
{
    int comp;
    int n;
    cout << "Enter a number:- ";
    cin >> n;
    int arr[n];
    cout << "Enter data:- ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    comp = merge_sort(arr,0,n-1);
    cout << "Sorted array is:- ";
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    cout << "Comparison :- " << comp;
    return 0;
}
