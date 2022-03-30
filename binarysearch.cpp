#include<bits/stdc++.h>
using namespace std;
int binary_search(int *arr,int l,int h,int num)
{
    if(l > h)
    {
        return 0;
    }
    int mid = (l+h)/2;
    if(arr[mid] == num)
    {
        return arr[mid];
    }
    if(arr[mid] > num)
    {
        return binary_search(arr,l,mid,num);
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
    if(binary_search(arr,l,h,num))
    {
        cout << "Data found:- " << binary_search(arr,l,h,num) << endl;
    }
    else{
        cout << "Data not found";
    }
    return 0;
}

