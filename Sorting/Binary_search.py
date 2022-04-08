# Binary search using python

def binary_search(a,l,h,key):
    mid = (l+h)//2
    if(l > h):
        return -1
    if(a[mid] == key):
        return mid
    if(a[mid] > key):
        return binary_search(a,l,mid-1,key)
    return binary_search(a,mid-1,h,key)
n = int(input("Enter Size of list:- "))
a = []
for i in range (0,n):
    p = int(input())
    a.append(p)
a.sort();
key = int(input("Enter Key:- "))
index = binary_search(a,0,n-1,key)
if(index == -1):
    print("Data not found")
else:
    print("Data found at:- ",index)
