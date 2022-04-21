#include <iostream>
using namespace std;
int merge(int *arr,int l,int mid,int h,int *comp)
{
    int inver = 0;
    int i=l,j=mid+1,k=l;
    int brr[h+1];
    while(i <= mid && j <= h)
    {
        *comp = *comp + 1;
        if(arr[i] <= arr[j])
        {
            brr[k++] = arr[i++];
        }
        else {
            inver += (mid+1-i);
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
    return inver;
}
int merge_sort(int *arr,int l,int h,int *comp)
{
    int mid;
    int inver = 0;
    if(l < h)
    {
        mid = (l+h)/2;
        inver += merge_sort(arr,l,mid,comp);
        inver += merge_sort(arr,mid+1,h,comp);
        inver += merge(arr,l,mid,h,comp);
    }
    return inver;
}
int main()
{
    int comp = 0;
    int inver = 0;
    int n;
    cout << "Enter a number:- ";
    cin >> n;
    int arr[n];
    cout << "Enter data:- ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    inver = merge_sort(arr,0,n-1,&comp);
    cout << "Sorted array is:- ";
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    cout << "Comparison :- " << comp << endl;
    cout << "Inversion :- " << inver;
    return 0;
}
