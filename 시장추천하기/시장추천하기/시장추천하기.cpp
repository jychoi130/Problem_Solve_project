/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������
���� ��õ�ϱ�*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	int n; //�ĺ����� ���� �Է¹��� ���� ����
	cin >> n;//�ĺ��� �� �Է�

	map<string, int> frequencyMap; 
	//�ĺ��� �̸��� ǥ�� �����ϴ� �ʺ��� ����
	int maxFrequency = 0;//�ִ� ��ǥ��

	for (int i = 0; i < n; i++) {//�ĺ��� �� ��ŭ �ݺ�
		string st;//�ĺ��� �̸����� ����
		cin >> st;//�̸� �Է�
		frequencyMap[st]++; //�̸��� ���� value�� ����������
		int k = frequencyMap[st];//k���� value�� �� ��ǥ�� �Է³���
		if (k > maxFrequency) {//���� ��ǥ���� �ִ� ��ǥ������ ũ��
			maxFrequency = k;//�ִ� ��ǥ���� �ٲ��ش�
		}
	}
	cout << maxFrequency << endl; //�ִ� ��ǥ�� ���

	map<string, int>::iterator it; //�ĺ� ����ϱ� ���� iterator ���� ����
	for (it = frequencyMap.begin(); it != frequencyMap.end(); it++)
	{
		if (it->second == maxFrequency) //�ִ� ��ǥ���� �����ϴ� Ű ���� ������
			printf("%s ", it->first.c_str());//Ű �� �ĺ��̸��� ����Ѵ�.
	}
}