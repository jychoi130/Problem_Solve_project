#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1000000; 
vector<int> FIBONACCI_TABLE;

vector<int> makeFibonacciTable(int n) //피보나치 값 
{
	const int MOD = 100000000; //MOD값 지정

	vector<int> ret(n + 1);
	ret[1] = 0;
	ret[2] = 1;
	for (int i = 3; i <= n; ++i) //피보나치 수열 계산
	{
		ret[i] = ret[i - 1] + ret[i - 2]; 
		ret[i] %= MOD; //MOD값 넘으면 MOD의 나머지만 출력
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
	FIBONACCI_TABLE.clear(); //초기화
	return 0;
}
