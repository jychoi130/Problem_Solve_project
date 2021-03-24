/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������
������׷�*/

#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>

using namespace std;

class Histogram { //������׷� Ŭ���� ����
public:
	int height;//����
	int leftX;//���ʺ� x ��ǥ
	int rightX;//�����ʺ� x ��ǥ

	Histogram() {	}
	Histogram(int index, int height) {
		this->leftX = index;
		this->rightX = this->leftX + 1;
		this->height = height;
	}
};

long long getLargestRectangleArea(const vector<Histogram>&histograms) {
	long long answer = 0;//�ִ� ���簢�� ����
	//int�� ����� overflow �߻�
	stack<Histogram>stk;
	stk.push(Histogram(-1, 0));
	for (int i = 0; i < histograms.size() + 1; i++) //������������ Ȯ��
	{
		Histogram h;
		if (i < histograms.size()) {
			h = histograms[i];
		}
		else {
			h = Histogram(histograms.size(), 0); //���� �����ʿ� ���� 0���� ���� ������׷� ����
		}

		while (stk.size() > 1 && stk.top().height > h.height) {//Ȯ�� ���ϸ� ����
			Histogram lh = stk.top();
			stk.pop();
			Histogram bh = stk.top();//���� �� ž ����
			long long width = abs(h.leftX - bh.rightX); //���̷� ���α��� 
			long long height = lh.height;//���� ���� ����
			long long area = width * height; //��������

			answer = max(answer, area);//�� ����
		}
		stk.push(h); //h �߰�
	}
	return answer;
}

void process(int caseIndex) {
	int n;//�׷��� ����
	cin >> n;

	vector<Histogram> histograms;
	for (int i = 0; i < n; i++) {
		int height;
		cin >> height;
		histograms.push_back(Histogram(i, height)); //�ε����� ���� ����
	}
	long long answer = getLargestRectangleArea(histograms);//���� ū ���� ��ȯ
	cout << answer << endl;
}

int main() {
	int caseSize; //���̽� ������ �Է¹���
	cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) { //���̽� �����ŭ ��������
		process(caseIndex);
	}
}