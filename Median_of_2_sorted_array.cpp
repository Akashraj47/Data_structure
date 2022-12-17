#include <bits/stdc++.h>
using namespace std;

double func(vector<int> &array1, vector<int> &array2)
{
    int n1 = array1.size();
    int n2 = array2.size();
    int mid, cut;
    int low = 0;
    int high = n1;
    int l1, l2;
    int r1, r2;
    while (low <= high)
    {
        mid = (low + high) / 2;
        cut = ((n1 + n2 + 1) / 2) - mid;

        (mid == 0) ? (l1 = INT_MIN) : (l1 = array1[mid - 1]);
        (cut == 0) ? (l2 = INT_MIN) : (l2 = array2[cut - 1]);

        (mid == n1) ? (r1 = INT_MAX) : (r1 = array1[mid]);
        (cut == n2) ? (r2 = INT_MAX) : (r2 = array2[cut]);

        if (l1 <= r2 && l2 <= r1)
        {
            if ((n1 + n2) % 2 == 0)
            {
                return ((max(l1, l2)) + (min(r1, r2))) / 2.0;
            }
            else
            {
                return max(l1, l2);
            }
        }
        else if (l1 > r2)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return 0;
}
double MedianOfArrays(vector<int> &array1, vector<int> &array2)
{
    int n1 = array1.size();
    int n2 = array2.size();
    if (n1 <= n2)
    {
        return func(array1, array2);
    }
    else
    {
        return func(array2, array1);
    }
}

int main()
{
    int m, n;
    cout << "Enter size of first sorted array:- ";
    cin >> m;
    cout << "Enter values in first sorted array:- ";
    vector<int> array1(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> array1[i];
    }
    cout << "Enter size of second sorted array:- ";
    cin >> n;
    cout << "Enter values in second sorted array:- ";
    vector<int> array2(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> array2[i];
    }
    cout << "Median is:- " << MedianOfArrays(array1, array2) << endl;
    return 0;
}
