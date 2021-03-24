/*전자컴퓨터공학부 소프트웨어공
180078 최지연*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_SERIAL_NUMBER = 100000;

void fillFrequencyTable(const vector<int> & data, int n, vector<int> &table)
{
	table.clear(); //초기화
	table.resize(MAX_SERIAL_NUMBER + 1, 0); //크기조정, vector 컨테이너에 요소 추가,초기화
	for (int i = 0; i < n; ++i) //개수 세기
	{
		int serial = data[i];
		table[serial] += 1;
	}
}
vector<int> getUniqueElements(const vector<int>&data, int n)
{
	vector<int> ret;
	vector<int> table;
	fillFrequencyTable(data, n, table); //개수 확인하는 함수

	for (int number = 1; number < MAX_SERIAL_NUMBER; number += 1)
		if (table[number] == 1)
			ret.push_back(number); //이미 있으면 값 제거

	return ret;
}
int main()
{
	int n;
	cin >> n; //입력받을 개수 입력
	
	vector<int> data = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> data[i];

	const vector<int> answer = getUniqueElements(data, n);

	for (int i = 0; i < answer.size(); ++i) //값 출력
	{
		if (i > 0)
			cout << " ";
		cout << answer[i];
	}
	return 0;
}