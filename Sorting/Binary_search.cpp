#include<bits/stdc++.h>
using namespace std;
int binary_search(int *arr,int l,int h,int num)
{
    if(l > h)
    {
        return -1;
    }
    int mid = (l+h)/2;
    if(arr[mid] == num)
    {
        return mid;
    }
    if(arr[mid] > num)
    {
        return binary_search(arr,l,mid-1,num);
    }
    return binary_search(arr,mid+1,h,num);
}
int main()
{
    int n;
    cout << "Enter size of array:- ";
    cin >> n;
    int arr[n];
    int l=0,h=n-1,num;
    cout << "Enter data:- ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cout << "Enter data to search:- ";
    cin >> num;
    sort(arr,arr+n);
    int index = binary_search(arr,l,h,num);
    if(index == -1)
    {
        cout << "Data not found";
    }
    else{
        cout << "Data found at index:- " << index << endl;
    }
    return 0;
}
