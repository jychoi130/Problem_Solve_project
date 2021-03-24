#include<iostream>
using namespace std;
#define max 9

int n, m;
bool check[max];
int arr[max];

void find(int a)
{
	if (a == m)
	{
		for (int i = 0; i < m; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			arr[a] = i;
			find(a + 1);
			check[i] = false;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	find(0);
	return 0;
}