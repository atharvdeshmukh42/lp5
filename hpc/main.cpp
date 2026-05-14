#include <iostream>
#include <vector>
#include <omp.h>
#include <climits>

using namespace std;

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    int minimum = INT_MAX;
    int maximum = INT_MIN;

    double start, end;

    // Start timer
    start = omp_get_wtime();

    // Parallel Sum
    #pragma omp parallel for reduction(+:sum)
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Parallel Minimum
    #pragma omp parallel for reduction(min:minimum)
    for(int i = 0; i < n; i++) {
        if(arr[i] < minimum) {
            minimum = arr[i];
        }
    }

    // Parallel Maximum
    #pragma omp parallel for reduction(max:maximum)
    for(int i = 0; i < n; i++) {
        if(arr[i] > maximum) {
            maximum = arr[i];
        }
    }

    // Average
    double average = (double)sum / n;

    // End timer
    end = omp_get_wtime();

    cout << "\nResults using Parallel Reduction:\n";

    cout << "Sum = " << sum << endl;
    cout << "Minimum = " << minimum << endl;
    cout << "Maximum = " << maximum << endl;
    cout << "Average = " << average << endl;

    cout << "Execution Time = " << end - start << " seconds" << endl;

    return 0;
}