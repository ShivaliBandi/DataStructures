#include <iostream>
using namespace std;
int binarySearch(int arr[], int key, int left, int right)
{
    //int mid=(left+right)/2; we can use this method for mid but when array is big in size this method fails we face issues so
    //we use another method for mid
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (key == arr[mid])
            return mid;
        if (arr[mid] > key)
            return binarySearch(arr, key, left, mid - 1);
        if (arr[mid] < key)
            return binarySearch(arr, key, mid + 1, right);
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    cout << binarySearch(arr, 3, 0, 5);

    return 0;
}