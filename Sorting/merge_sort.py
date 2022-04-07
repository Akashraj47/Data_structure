# Python code for merge sort


import sys
sys.setrecursionlimit(10**6)
def merge(a,l,mid,h):
    i = l
    j = mid+1
    b = []
    while(i<=mid and j<= h):
        if(a[i] < a[j]):
            b.append(a[i])
            i = i+1
        else:
            b.append(a[j])
            j = j+1
    while(i<=mid):
        b.append(a[i])
        i = i +1
    while(j<=h):
        b.append(a[j])
        j = j+1
    m=0
    for p in range(l,h+1):
        a[p] = b[m]
        m = m + 1
def merge_sort(a,l,h):
    if(l<h):
        mid = (l+h)//2
        merge_sort(a,l,mid)
        merge_sort(a,mid+1,h)
        merge(a,l,mid,h)
    else:
        return
a = [];
n = int(input("Enter size of list:- "))
print(n);
i = 0;
print("Enter data:- ")
for i in range(n):
    p = int(input())
    a.append(p)
i=0
merge_sort(a,0,n-1)
print("Sorted list is:- ")
print(a)
