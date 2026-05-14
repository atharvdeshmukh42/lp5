#include<iostream>
#include<vector>
#include<omp.h>

using namespace std;
void merge(vector<int>& a, int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    vector<int> temp;
    while(i <= m && j <= r)
    {
        if(a[i] < a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }
    while(i <= m)
        temp.push_back(a[i++]);

    while(j <= r)
        temp.push_back(a[j++]);

    for(int k = 0; k < temp.size(); k++)
    {
        a[l + k] = temp[k];
    }
}
void mergesort(vector<int>& a, int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            mergesort(a, l, m);
            #pragma omp section
            mergesort(a, m + 1, r);
        }
        merge(a, l, m, r);
    }
}
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    double start = omp_get_wtime();
    mergesort(a, 0, n - 1);
    double end = omp_get_wtime();
    cout << "\nSorted Array: ";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\nExecution Time = " << end - start;
    return 0;
}