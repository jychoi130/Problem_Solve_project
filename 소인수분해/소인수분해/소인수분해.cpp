/*전자컴퓨터공학부 소프트웨어공
180078 최지연*/
#include<iostream>
#include<vector>
using namespace std;

vector<int>factorize(int n) //소인수찾기
{
	vector<int> factors;
	for(int div=2;div*div<=n;div+=1)
		while (n%div == 0) //나머지가 0이면
		{
			factors.push_back(div); //원소 넣는다.
			n /= div;
		}
	if (n > 1)
		factors.push_back(n);
	return factors;
}
void process(int caseIndex)
{
	long long n;
	cin >> n;
	vector<int>factors = factorize(n);
	cout << "#" << caseIndex << ":" << endl;
	for (int i = 0; i < factors.size(); ++i)
	{
		if (i > 0)
			cout << " ";
		cout << factors[i];
	}
	cout << endl;
}
int main()
{
	int caseSize;
	cin >> caseSize;
	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex)
		process(caseIndex);
}