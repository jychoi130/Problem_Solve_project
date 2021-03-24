#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int **arr;
	*arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];



	return 0;
}