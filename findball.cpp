#include <iostream>

using namespace std;

int divideconquer(int arr[], int l, int r)
{
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) / 2;
    int num1 = divideconquer(arr, l, mid);

    int num2 = divideconquer(arr, mid + 1, r);

    if (arr[num1] != arr[num2])
    {
        if (arr[num1] < arr[num2] || arr[num1] > arr[num2])
        {
            return num1;
        }
        else
        {
            return num2;
        }
    }
    return num1;
}

int main()
{
    int arr[] = {2, 1, 2, 2, 2, 2, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num = divideconquer(arr, 0, n - 1);
    cout << num << endl;
    return 0;
}
