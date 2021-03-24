/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������
�������� ����*/

#include<iostream>
using namespace std;

int const NumMAX = 1000000;
bool check[NumMAX];

void Prime() //�����佺�׳׽� ü �̿��ؼ� �Ҽ� ����
{
	for (int i = 2; i*i < NumMAX; i++) 
	{
		if (!check[i])
			for (int j = i * i; j < NumMAX; j = j + i)
				check[j] = true;
	}//�Ҽ��� false �� ����
}
int main()
{
	int casenum; //���̽� ����
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
			if (!check[a]) //���� �Ҽ��� ���
			{
				b = x - a;
				if (!check[b]) //ã���� �ٷ� break
				{
					printf("%d = %d + %d \n", x, a, b);
					checking = 1; //�˰��� ����Ǵ� ���
					break;
				}
			}
		}
		if (checking == 0)//������ ������ ������� ���� ���
			printf("-1\n"); 
	}
	return 0;
}