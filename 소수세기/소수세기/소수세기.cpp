/*전자컴퓨터공학부 소프트웨어공
180078 최지연*/
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Sieve
{
public:
	int maximumValue;
	vector<bool> isPrime; //각 숫자별 소수 여부
	Sieve(int maximumValue)
	{
		this->maximumValue = maximumValue;
		this->isPrime.assign(maximumValue + 1, false); //초기화
		this->fillSieve();
	}
	bool isPrimeNumber(int num)const {
		return this->isPrime[num];
	}
	void fillSieve()
	{
		isPrime.assign(this->maximumValue, true); //모두 소수로 저장
		isPrime[0] = isPrime[1] = false; //0,1 소수 아니라고 저장
		for (int num = 2; num <= maximumValue; num += 1)
		{
			if (isPrime[num] == false) //이미 소수 아니라고 체크되면 패스
				continue;
			for (long long mul = (long long)num*num; mul <= maximumValue; mul += num)
			{
				int index = (int)mul; 
				isPrime[index] = false;//소수의 배수는 소수가 아니므로 false 저장
			}
		}
	}
};
vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve)
{
	vector<int>primes;
	for (int num = from; num <= to; num += 1)
	{
		if (sieve.isPrimeNumber(num))
		{
			primes.push_back(num);
		}
	}
	return primes;
}
void process(int caseIndex, const Sieve&sieve)
{
	int L, R;
	cin >> L >> R;
	vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve);
	cout << "Case #" << caseIndex << ":" << endl << (int)allPrimeNumbers.size() << endl;
}
int main()
{
	const int MAX_VALUE = 1000000; //범위 지정
	Sieve sieve = Sieve(MAX_VALUE);
	int caseSize;
	cin >> caseSize;
	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex)
		process(caseIndex, sieve);
	return 0;
}