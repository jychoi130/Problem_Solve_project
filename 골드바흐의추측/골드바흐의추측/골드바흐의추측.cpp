/*전자컴퓨터공학부 소프트웨어공
180078 최지연
골드바흐의 추측*/

#include<iostream>
using namespace std;

int const NumMAX = 1000000;
bool check[NumMAX];

void Prime() //에라토스테네스 체 이용해서 소수 구함
{
	for (int i = 2; i*i < NumMAX; i++) 
	{
		if (!check[i])
			for (int j = i * i; j < NumMAX; j = j + i)
				check[j] = true;
	}//소수를 false 값 취함
}
int main()
{
	int casenum; //케이스 개수
	int x, a, b;
	int checking = 0;
	scanf("%d", &casenum);

	Prime();

	for (int i = 1; i <= casenum; i++)
	{
		printf("Case #%d : ", i);
		scanf("%d", &x);
		for (int a = 2; a <= NumMAX; a++)
		{
			if (!check[a]) //값이 소수인 경우
			{
				b = x - a;
				if (!check[b]) //찾으면 바로 break
				{
					printf("%d = %d + %d \n", x, a, b);
					checking = 1; //알고리즘 실행되는 경우
					break;
				}
			}
		}
		if (checking == 0)//골드바흐 추측이 실행되지 않을 경우
			printf("-1\n"); 
	}
	return 0;
}