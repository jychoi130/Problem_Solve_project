/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_SERIAL_NUMBER = 100000;

void fillFrequencyTable(const vector<int> & data, int n, vector<int> &table)
{
	table.clear(); //�ʱ�ȭ
	table.resize(MAX_SERIAL_NUMBER + 1, 0); //ũ������, vector �����̳ʿ� ��� �߰�,�ʱ�ȭ
	for (int i = 0; i < n; ++i) //���� ����
	{
		int serial = data[i];
		table[serial] += 1;
	}
}
vector<int> getUniqueElements(const vector<int>&data, int n)
{
	vector<int> ret;
	vector<int> table;
	fillFrequencyTable(data, n, table); //���� Ȯ���ϴ� �Լ�

	for (int number = 1; number < MAX_SERIAL_NUMBER; number += 1)
		if (table[number] == 1)
			ret.push_back(number); //�̹� ������ �� ����

	return ret;
}
int main()
{
	int n;
	cin >> n; //�Է¹��� ���� �Է�
	
	vector<int> data = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> data[i];

	const vector<int> answer = getUniqueElements(data, n);

	for (int i = 0; i < answer.size(); ++i) //�� ���
	{
		if (i > 0)
			cout << " ";
		cout << answer[i];
	}
	return 0;
}