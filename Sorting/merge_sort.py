# Python code for merge sort

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
    for p in range(i,mid+1):
        b.append(a[p])
    for p in range(j,h+1):
        b.append(a[p])
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
a = [];
n = int(input("Enter size of list:- "))
print(n);
i = 0;
print("Enter data:- ")
for i in range(n):
    p = int(input())
    a.append(p)
merge_sort(a,0,n-1)
print("Sorted list is:- ")
print(a)
