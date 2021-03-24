/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������*/
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Sieve
{
public:
	int maximumValue;
	vector<bool> isPrime; //�� ���ں� �Ҽ� ����
	Sieve(int maximumValue)
	{
		this->maximumValue = maximumValue;
		this->isPrime.assign(maximumValue + 1, false); //�ʱ�ȭ
		this->fillSieve();
	}
	bool isPrimeNumber(int num)const {
		return this->isPrime[num];
	}
	void fillSieve()
	{
		isPrime.assign(this->maximumValue, true); //��� �Ҽ��� ����
		isPrime[0] = isPrime[1] = false; //0,1 �Ҽ� �ƴ϶�� ����
		for (int num = 2; num <= maximumValue; num += 1)
		{
			if (isPrime[num] == false) //�̹� �Ҽ� �ƴ϶�� üũ�Ǹ� �н�
				continue;
			for (long long mul = (long long)num*num; mul <= maximumValue; mul += num)
			{
				int index = (int)mul; 
				isPrime[index] = false;//�Ҽ��� ����� �Ҽ��� �ƴϹǷ� false ����
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
	const int MAX_VALUE = 1000000; //���� ����
	Sieve sieve = Sieve(MAX_VALUE);
	int caseSize;
	cin >> caseSize;
	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex)
		process(caseIndex, sieve);
	return 0;
}