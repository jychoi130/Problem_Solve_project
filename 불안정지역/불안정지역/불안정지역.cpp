/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������
�Ҿ��� ����*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class City {
public:
	int index; //���� �ε���
	int income; //���� �ҵ�

	City(int index, int income) { //���� ������
		this->index = index;
		this->income = income;
	}
	bool operator<(const City&o)const {
		return this->income < o.income;
	}
	bool operator>(const City&o)const {
		return this->income > o.income;
	}//��� ���� �߰��ؾ� ������ ������ ��� ���踦 ���� ���ΰ��� �� �� �ִ�
};

int getMaximumRangeDifference(int n, int k, const vector<City>&cities) {
	int answer = 0;

	priority_queue<City, vector<City>, greater<City>> rangeMinimum;
	//�ҵ� ���� ���ú��� ���ϴ� �켱���� ť
	priority_queue<City> rangeMaximum; //�ҵ� ���� ���ú��� ���ϴ� �켱���� ť

	for (int i = 0; i < k - 1; i++) {
		rangeMaximum.push(cities[i]);//ū ���� ž
		rangeMinimum.push(cities[i]);//���� ���� ž
	}
	for (int i = k - 1; i < n; i++) {
		rangeMaximum.push(cities[i]); 
		rangeMinimum.push(cities[i]);
		while (rangeMaximum.top().index < i - k + 1)rangeMaximum.pop();//������ ���� ���� ����
		while (rangeMinimum.top().index < i - k + 1)rangeMinimum.pop(); //������ ���� ���� ����
		answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income);//ū ������ ������Ʈ
	}
	return answer; //�� ��ȯ�� ��
}

void process(int caseIndex) {
	int n, k;
	cin >> n >> k; //������ ��,������ ���� ��
	vector<City>cities;

	for (int i = 0; i < n; i += 1) {
		int income;
		cin >> income;
		cities.push_back(City(i, income)); //�� �־��ش�
	}

	int answer = getMaximumRangeDifference(n, k, cities); //���� Ǯ�� ����

	cout << answer << endl; //�� ���
}

int main() {
	int caseSize; //���̽� ���� 
	cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1)
		process(caseIndex); //���̽� ������ŭ ���μ��� ������
}