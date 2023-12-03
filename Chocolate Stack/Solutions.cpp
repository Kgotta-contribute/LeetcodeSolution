#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum difference between maximum
// and minimum values of chocolate distribution.
int findMinDiff(int arr[], int n, int m)
{
    // if there are no chocolates or number of students is 0
    if (m == 0 || n == 0)
        return 0;

    // Sort the given packets
    sort(arr, arr + n);

    // Number of students cannot be more than number of packets
    if (n < m)
        return -1;

    // Initialize the minimum difference to a large value
    int min_diff = INT_MAX;

    // Find the subarray of size m such that the difference
    // between the last (maximum in case of sorted) and first
    // (minimum in case of sorted) elements of subarray is minimum.
    for (int i = 0; i + m - 1 < n; i++) {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}

int main()
{
    int arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int m = 7; 
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum difference is " << findMinDiff(arr, n, m);

    return 0;
}





// JAVA

import java.util.Arrays;
public class ChocolateDistribution {

    static int findMinDiff(int arr[], int n, int m) {
        if (m == 0 || n == 0)
            return 0;

        Arrays.sort(arr);

        if (n < m)
            return -1;

        int min_diff = Integer.MAX_VALUE;

        for (int i = 0; i + m - 1 < n; i++) {
            int diff = arr[i + m - 1] - arr[i];
            if (diff < min_diff)
                min_diff = diff;
        }
        return min_diff;
    }

    public static void main(String[] args) {
        int arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
        int m = 7;
        int n = arr.length;

        System.out.println("Minimum difference is " + findMinDiff(arr, n, m));
    }
}
