/*������ǻ�Ͱ��к� ����Ʈ�����а�
180078 ������*/
#include <iostream>
using namespace std;

bool checkprime(int p)//�Ҽ����� Ȯ���ϴ� �Լ�
{
	if (p == 1) { //���� 1�� �Է��� ��� �Ҽ��� �ƴѴ�
		return false;
	}
	else if (p == 2) {//2�� �Է��� ��� �Ҽ��̴�
		return true;
	}
	else {//�ٸ� ���ڸ� �Է��� ���
		for (int i = 2; i < p; i++)//2~�Է��� ����-1����
		{
			if (p%i == 0)//�������� ���غ���
				return false;//�������� ������ ������>>�Ҽ��� �ƴϴ�
		}
		return true;//������ ������ �Ҽ�
	}
}
void Tcase(int index)//�Ҽ� Ȯ���� ���� �Է¹ް� ��� ����Լ�
{
	int prime;//���� �Է� ���� ����
	cin >> prime;//���� ����
	bool result = checkprime(prime);//�Ҽ����� Ȯ���ϴ� �Լ�
	cout << "Case #" << index << endl; 
	if (result) //���� ����� ���̴�
		cout << "YES" << endl;//yes���
	else//����� �����̸�
		cout << "NO" << endl;//no���
}
int main()
{
	int num;
	cin >> num;//case ���� �Է�

	for (int i = 1; i <= num; i++)//case������ŭ ���� �Է¹޴� �Լ� ����
	{
		Tcase(i);
	}

	return 0;
}