#include <iostream>
using namespace std;

long long mergeCount(long long arr[], long long temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    long long inv = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv += mid - i + 1;
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int x = left; x <= right; x++) arr[x] = temp[x];
    return inv;
}

long long countInv(long long arr[], long long temp[], int left, int right) {
    if (left >= right) return 0;
    int mid = (left + right) / 2;
    long long inv = 0;

    inv += countInv(arr, temp, left, mid);
    inv += countInv(arr, temp, mid + 1, right);
    inv += mergeCount(arr, temp, left, mid, right);

    return inv;
}

int main() {
    long long arr[] = {2, 4, 1, 3, 5};
    int n = 5;
    long long temp[n];

    cout << countInv(arr, temp, 0, n - 1);
    return 0;
}
