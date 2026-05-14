#include<iostream>
#include<omp.h>
#include<vector>

using namespace std;

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

    for(int i = 0; i < n; i++)
    {
        // Even phase
        #pragma omp parallel for
        for(int j = 0; j < n - 1; j += 2)
        {
            if(a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }

        // Odd phase
        #pragma omp parallel for
        for(int j = 1; j < n - 1; j += 2)
        {
            if(a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }

    double end = omp_get_wtime();

    cout << "\nSorted Array: ";

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << "\nExecution Time = " << end - start << " seconds";

    return 0;
}