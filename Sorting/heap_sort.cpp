// HEAP SORT

#include<bits/stdc++.h>
using namespace std;
void heapify(int *a,int i,int n){
    int l = i;
    int li = 2*i + 1;
    int ri = 2*i + 2;
    if(ri < n && a[ri] > a[l]){
        l = ri;
    }
    if(li < n && a[li] > a[l]){
        l = li;
    }
    if(l != i){
        swap(a[l],a[i]);
        heapify(a,l,n);
    }

}
void buildheap(int *a,int n){
    for(int i = n-1;i>=0;i--){
        heapify(a,i,n);
    }
}
void heapsort(int *a,int n){
    buildheap(a,n);
    for(int i = n-1;i>0;i--){
        swap(a[0] , a[i]);
        n = n-1;
        heapify(a,0,n);
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter size of n:- ";
    cin >> n;
    int a[n];
    cout << "Enter data:- ";
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    heapsort(a,n);
    cout << "Sorted array is:- ";
    for(int i = 0;i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}
