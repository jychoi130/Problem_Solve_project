#include<iostream>

using namespace std;
int change(int arr[], int n, int a) {
	int min =a;
	for (int i = a; i < n; i++) {
		if (arr[i] < arr[min])
			min = i;
	}
	cout << min << endl;
	return min;
}
void check(int arr[], int n) {
	int min,a=0,tmp;
	for (int i = 0; i < n; i++) {
		min = change(arr, n, i);
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	
}

int main()
{
	int n;
	cin >> n;
	int *arr;
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	check(arr, n);
	return 0;
}