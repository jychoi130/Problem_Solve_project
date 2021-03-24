/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> getPossibleTargets(int n, int m, int *cards, int* targets)
{
	vector<int> possibleTargets; //���� �� �ִ� ��÷ ��ȣ
	
	sort(cards, cards + n);//���̳ʸ� ��ġ(���ĵǾ��־����) ����ϱ����� ����

	for (int i = 0; i < m; i++) 
	{
		int k = targets[i];
		bool possible = false;

		for (int j = 0; j < n; ++j) 
		{
			int x = cards[j];
			for (int p = 0; p <= j; p += 1) //�ߺ� ���̱����� j����
			{
				int y = cards[p];
				int z = k - (x + y); //z���� ã�´�.

				if (binary_search(cards, cards + n, z) == true)
				{
					possible = true;
					break;
				}
				if (possible) //ã������ Ż��
					break;
			}
		}
		if (possible)
			possibleTargets.push_back(k); //ã���� k�� ������ �־��ش�
	}
	sort(possibleTargets.begin(), possibleTargets.end()); //�� ����
	return possibleTargets;
}
int main()
{
	int n, m;
	cin >> n >> m; //ī�� ��, �ĺ� ��
	
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