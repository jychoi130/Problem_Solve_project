/*������ǻ�Ͱ��к� ����Ʈ�����а�
180078 ������*/

#include <iostream>
using namespace std;

bool isinside(long long x, long long y, long long r) //�ȼ��� ���� ���ԵǴ��� Ȯ��
{
	long long sqd = x * x + y * y;  
	if (sqd < r*r) //���� ���� ũ�⺸�� ������
		return true;
	return false;
}
void testcase(int caseindex)
{
	long long r; //������ ���� ����
	scanf("%lld", &r); //������ �Է�
	long long sum = 0; //1��и��� �ȼ� ���� 
	long long y = r; //������ ���� y�࿡ �Է�
	for (long x = 0; x <= r; x++)
	{
		long long height = 0;
		for (; y >= 0; y--) //y���� ���������� Ȯ��
		{
			if (isinside(x, y, r)) { //isinside�� ���̸� ���� �ȼ��� ���� ���Եȴ�.
				height = y + 1; 
				break;
			}
		}
		sum += height; //������ �����ش�
	}
	cout << "#" << caseindex << endl;
	cout << sum * 4 << endl; //�߽��� �������� �и��� 4�� ����
}
int main()
{
	int casesize; //���̽� ���� ���� ����
	cin >> casesize;
	
	for (int caseindex = 1; caseindex <= casesize; caseindex++) //���̽� ������ŭ
		testcase(caseindex); //�׽�Ʈ���̽��Լ� ����

	return 0;
}