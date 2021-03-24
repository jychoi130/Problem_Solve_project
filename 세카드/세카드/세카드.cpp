/*전자컴퓨터공학부 소프트웨어공
180078 최지연*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> getPossibleTargets(int n, int m, int *cards, int* targets)
{
	vector<int> possibleTargets; //만들 수 있는 당첨 번호
	
	sort(cards, cards + n);//바이너리 서치(정렬되어있어야함) 사용하기위한 정렬

	for (int i = 0; i < m; i++) 
	{
		int k = targets[i];
		bool possible = false;

		for (int j = 0; j < n; ++j) 
		{
			int x = cards[j];
			for (int p = 0; p <= j; p += 1) //중복 줄이기위해 j까지
			{
				int y = cards[p];
				int z = k - (x + y); //z값을 찾는다.

				if (binary_search(cards, cards + n, z) == true)
				{
					possible = true;
					break;
				}
				if (possible) //찾았으면 탈출
					break;
			}
		}
		if (possible)
			possibleTargets.push_back(k); //찾으면 k를 변수에 넣어준다
	}
	sort(possibleTargets.begin(), possibleTargets.end()); //재 정렬
	return possibleTargets;
}
int main()
{
	int n, m;
	cin >> n >> m; //카드 수, 후보 수
	
	int *cards = new int[n];
	int *targets = new int[m];


	for (int i = 0; i < n; i++)
		cin >> cards[i];
	for (int i = 0; i < m; i++)
		cin >> targets[i];
	
	vector<int> answers = getPossibleTargets(n, m, cards, targets);

	if (answers.size() == 0)
		cout << "NO" << endl;
	else
	{
		for (int i = 0; i < answers.size(); i++)
		{
			if (i > 0)
				cout << " ";
			cout << answers[i];
		}
	}
	delete[] cards;
	delete[] targets;

	return 0;
}