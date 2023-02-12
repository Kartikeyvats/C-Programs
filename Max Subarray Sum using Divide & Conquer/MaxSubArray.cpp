#include<bits/stdc++.h>
using namespace std;

int max_crossing_sum(int arr[], int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m+1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    return left_sum + right_sum;
}

int max_subarray_sum(int arr[], int l, int h)
{
    if (l == h)
        return arr[l];
    int m = (l + h)/2;
    return max(max(max_subarray_sum(arr, l, m),
                    max_subarray_sum(arr, m+1, h)),
                max_crossing_sum(arr, l, m, h));
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int max_sum = max_subarray_sum(arr, 0, n-1);
    cout << "Maximum subarray sum is " << max_sum << endl;
    return 0;
}
