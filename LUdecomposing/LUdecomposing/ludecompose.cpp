#include<iostream>
#include<conio.h>

int main()
{
	int n, row, column;

	printf("행렬의 크기를 입력하세요:");
	scanf("%d", &n);

	float A[20][20];
	printf("\n\nA행렬을 입력하세요\n\n");

	for (row = 0; row < n; row++)
		for (column = 0; column < n; column++)
			scanf("%f", &A[row][column]);

	float lowertriangle[20][20];
	float uppertriangle[20][20];

	for (row = 0; row < n; row++)
		for (column = 0; column < n; column++)
		{
			if (row > column)
				uppertriangle[row][column] = 0.0;
			if (row < column)
				lowertriangle[row][column] = 0.0;
			if (row == column)
				lowertriangle[row][column] = 1.0;
		}

	for (int i = 0; i < n; i++)
	{
		uppertriangle[i][i] = A[i][i];
		for (int j = i + 1; j < n; j++)
		{
			uppertriangle[i][j] = A[i][j];
			lowertriangle[j][i] = A[j][i] / uppertriangle[i][i];
		}
		for (row = i + 1; row < n; row++)
			for (column = i + 1; column < n; column++)
				A[row][column] = A[row][column] - lowertriangle[row][i] * uppertriangle[i][column];
	}

	printf("\n\n상삼각행렬\n\n");
	for (row = 0; row < n; row++)
	{
		for (column = 0; column < n; column++)
			printf("%.2f ", uppertriangle[row][column]);
		printf("\n");
	}

	printf("\n\n단위하삼각행렬\n\n");
	for (row = 0; row < n; row++)
	{
		for (column = 0; column < n; column++)
			printf("%.2f ", lowertriangle[row][column]);
		printf("\n");
	}

	getch();
}