#include <iostream>
using namespace std;

void RecursiveInsertionSort(int arr[], int n)
{
	if (n <= 1)
		return;
	RecursiveInsertionSort(arr, n - 1);
	int last;
	last = arr[n - 1];
	int j;
	j = n - 2;
	while (j >= 0 && arr[j] > last)
	{
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = last;
}



void join(int arr[], int left[], int right[],
	int l, int m, int r)
{
	int i = 0;
	while (i <= m - l) {
		arr[i] = left[i];
		i++;
	}
	int j = 0;
	while(j < r - m)
	{
		arr[i + j] = right[j];
		j++;
	}
}

void split(int arr[], int left[], int right[],
	int l, int m, int r)
{
	int i = 0;
	for (; i <= m - l; i++)
		left[i] = arr[i * 2];
	i = 0;
	for (; i < r - m; i++)
		right[i] = arr[i * 2 + 1];
}

void generateWorstCase(int arr[], int l,
	int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		int* left = new int[m - l + 1];
		int* right = new int[r - m];
		split(arr, left, right, l, m, r);
		generateWorstCase(left, l, m);
		generateWorstCase(right, m + 1, r);
		join(arr, left, right, l, m, r);
	}
}

int main()
{

	long long int n;
	cin >> n;
	int* array = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}

	RecursiveInsertionSort(array, n);
	generateWorstCase(array, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << array[i] << " ";

	return 0;
}


