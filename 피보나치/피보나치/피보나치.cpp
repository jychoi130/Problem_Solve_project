/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������*/
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1000000; 
vector<int> FIBONACCI_TABLE;

vector<int> makeFibonacciTable(int n) //�Ǻ���ġ �� 
{
	const int MOD = 100000000; //MOD�� ����

	vector<int> ret(n + 1);
	ret[1] = 0;
	ret[2] = 1;
	for (int i = 3; i <= n; ++i) //�Ǻ���ġ ���� ���
	{
		ret[i] = ret[i - 1] + ret[i - 2]; 
		ret[i] %= MOD; //MOD�� ������ MOD�� �������� ���
	}
	return ret;
}
int getFibo(int n)
{
	int answer = FIBONACCI_TABLE[n];
	return answer;
}
int main()
{
	FIBONACCI_TABLE = makeFibonacciTable(MAX_N);
	int caseSize;
	cin >> caseSize;
	
	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex)
	{
		int n;
		cin >> n;

		int answer = getFibo(n);
		cout << answer << endl;
	}
	FIBONACCI_TABLE.clear(); //�ʱ�ȭ
	return 0;
}