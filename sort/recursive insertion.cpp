#include <iostream>

using namespace std;

void Sort(int arr[], int n)
{
   
    if (n <= 1) {
        return;
    }
    Sort(arr, n - 1);
    int key = arr[n - 1];
    int i = n - 2;
    while (i > -1 && arr[i] >= key + 1)
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = key;
}
int main()
{
    int n;
    cin >> n;
    int arr[100000];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i]<<" ";
    }
}
